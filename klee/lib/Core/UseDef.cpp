#include "../../include/klee/Core/UseDef.h"

#include "llvm/IR/DebugInfoMetadata.h"

using namespace llvm;
using namespace klee;

std::string contract_name;

UseDef::UseDef(){}

void UseDef::printValue(Value* v)
{
    v->printAsOperand(outs(), true, nullptr);
    outs() << "\n";
}

std::string valueToString(Value* val) {
    std::string str;
    llvm::raw_string_ostream instruction_name(str);
    val->printAsOperand(instruction_name, false);
    return instruction_name.str();
}

void UseDef::printVector(std::vector<Value*> vec)
{
    for(auto itr = vec.begin(); itr != vec.end(); ++itr){
        printValue(*itr);
    }
}

void UseDef::printList(std::list<Value*> vec)
{
    for(auto itr = vec.begin(); itr != vec.end(); ++itr){
        printValue(*itr);
    }
}


int UseDef::indexFind(Value* var, std::map<Value*, Value*> &parent, std::map<Value*, int> &index)
{
	// if(var == nullptr)
	// 	return index[var];
	if(parent[var] == nullptr)
		return index[var];
	else
		return indexFind(parent[var], parent, index);
}


BitVector UseDef::setUsers(Function* f, BitVector prev, std::vector<void*> domain, std::map<void*, int>domainToIndex, std::map<Value*, Value*>& classVarParent)
{
	BitVector retVal = prev;
	int size = prev.size();
    // if(getFunctionName(f) == "vote")
    //     outs() << "\n" << f->getName() << "\n";
	for(auto itr = domain.begin(); itr != domain.end(); ++itr){
		int index = domainToIndex[*itr];
        Value* valItr = (Value*)*itr;
		if(prev[index]) {
            if(getFunctionName(f) == "vote"){
                printValue(valItr);
            }
            for(auto U: ((Value*)(*itr))->users()){
				if(Instruction *inst = dyn_cast<Instruction>(U)){
                    if(StoreInst* st = dyn_cast<StoreInst>(inst)){
                        Value* arg = (Value*)st->getOperand(1);
                        Type* t = arg->getType();
                        if(t->isPointerTy() && ((PointerType*)t)->getElementType()->isPointerTy()){
                            retVal.set(domainToIndex[(void*)arg]);
                            classVarParent[arg] = valItr;
                        }
					}
					else if(CallInst* call = dyn_cast<CallInst>(inst)){
						Function* fn = call->getCalledFunction();
                        std::string callName = getFunctionName(fn);
		                if(fn != NULL){
		                    if((fn->getReturnType())->isVoidTy()){
		                    //     if((fn->isIntrinsic() && call->getNumArgOperands() > 0) {
		                    //         Value* arg = (Value*)call->getArgOperand(0);
		                    //         retVal.set(domainToIndex[(void*)arg]);
                            //         classVarParent[arg] = valItr;
                            //         // outs() << domainToIndex[(void*)arg] << " ";
                            //         // printValue(arg);
                            //     }
		                    }
		                    else{
		                        retVal.set(domainToIndex[(void*)(Value*)call]);
                                classVarParent[(Value*)call] = valItr;
                                if((fn->isIntrinsic() || callName == "memcpy" || callName == "memset" || callName == "memmove") && call->getNumArgOperands() > 0){
                                    Value* arg = (Value*)call->getArgOperand(0);
                                    Type* t = arg->getType();
                                    if(t->isStructTy()){
                                        if(t->getStructName().str().find(contract_name) != std::string::npos){
                                            retVal.set(domainToIndex[(void*)arg]);
                                            if(classVarParent.find(arg) == classVarParent.end())
                                            classVarParent[arg] = valItr;
                                        }
                                    }
                                }
                            }
		                }
					}
					else if(inst->isTerminator()){
					}
                    else if(BitCastInst* bc = dyn_cast<BitCastInst>(inst)){
                        // outs() << "bc:" << *inst << '\n';
                        retVal.set(domainToIndex[(void*)bc]);
                        classVarParent[(Value*)bc] = valItr;
                        if(bc->getNumOperands() > 0){
                            Value* v = bc->getOperand(0);
                            if(classVarParent.find(v) == classVarParent.end()){
                                if(classVarParent.find((Value*)bc) != classVarParent.end()){
                                    // outs() << "bc2:" << *inst << '\n';
                                    classVarParent[v] = (Value*)bc;
                                    retVal.set(domainToIndex[(void*)v]);
                                }
                            }
                        }
                    }
					else{
						retVal.set(domainToIndex[(void*)inst]);
                        classVarParent[(Value*)inst] = valItr;
                    }
				}
			}
		}
	}
    // outs() << "\n" << "init parent" << '\n';
	// for(auto itr = classVarParent.begin(); itr != classVarParent.end(); ++itr){
    //     printValue(itr->first);
    //     if(itr->second != nullptr){
    //         outs() << ":";
    //         printValue(itr->second);
    //     }
    // }
	return retVal;
}

std::list<Value*> UseDef::getAllUsers(Function* f, std::list<Value*> classVar, std::map<Value*, Value*>& classVarParent)
{
	std::vector<void*> domain;

	for(Function::iterator bb = f->begin(); bb != f->end(); ++bb){
		for(BasicBlock::iterator i = bb->begin(); i != bb->end(); ++i){
			Instruction* inst = dyn_cast<Instruction>(i);

			// domain = instruction/arguments/global variables used as operands
			for (User::op_iterator OI = inst->op_begin(), OE = inst->op_end(); OI != OE; ++OI){
				Value *val = *OI;
				if (isa<Instruction>(val) || isa<Argument>(val) ||isa<GlobalVariable>(val)){
					if(std::find(domain.begin(), domain.end(), val) == domain.end())
						domain.push_back((void*)val);
				}
			}

            if(Value* v = dyn_cast<Value>(inst)){
                std::string val = valueToString(v);
                // outs() << "string:" << val << '\n';
                if(valueToString(v).find("badref") == std::string::npos){
                    if(std::find(domain.begin(), domain.end(), (void*)v) == domain.end()){
                        domain.push_back((void*)v);
                    }
                }
            }
		}
	}
	std::map<void*, int> domainToIndex;
    // setting the domain to index mapping
	for (unsigned int i = 0; i < domain.size(); ++i){
        domainToIndex[(void*)domain[i]] = i;
	}

	BitVector valUsers(domain.size(), false);
	// outs() << "\n\nsetting:\n";

	for(auto itr = domain.begin(); itr != domain.end(); ++itr){
		if(std::find(classVar.begin(), classVar.end(), (Value*)*itr) != classVar.end()){
			valUsers.set(domainToIndex[(void*)*itr]);
		}
	}

	BitVector newU = valUsers;
	BitVector prevU(domain.size(), false);
	while(prevU.count() != newU.count()){
		prevU = newU;
		newU = setUsers(f, prevU, domain, domainToIndex, classVarParent);
		// prev = new;
	}

	std::list<Value*> users;
	for (auto itr = domain.begin(); itr != domain.end(); itr++){
        if(newU[domainToIndex[*itr]]){
			users.push_back((Value*)*itr);
		}
	}
	return users;
}

void UseDef::setState(Function* f, std::list<Value*>& classVar, std::map<Value*, Value*>& classVarParent, std::map<Value*, int>& classVarToIndex)
{
	std::string functionName = getFunctionName(f);

	for(auto itr = classVar.begin(); itr != classVar.end(); ++itr){
        if(classVarToIndex.find((Value*)*itr) == classVarToIndex.end())
            classVarToIndex[(Value*)*itr] = indexFind((Value*)*itr, classVarParent, classVarToIndex);        
	}
    for(auto itr = classVar.begin(); itr != classVar.end(); ++itr){
		for (User *U: (*itr)->users()){
			if (Instruction *inst = dyn_cast<Instruction>(U)){
				if(inst->mayWriteToMemory()){
					if(inst->getOpcode() == Instruction::Store){
						if(inst->getNumOperands() > 1 && inst->getOperand(1) == *itr){
							writeState[functionName].insert(classVarToIndex[(Value*)*itr]);
						}
					}
					else if(CallInst* call_inst = dyn_cast<CallInst>(inst)){
						Function* fn = call_inst->getCalledFunction();
						if(fn != NULL){
							std::string callName = fn->getName();
							if((fn->isIntrinsic() || callName == "memcpy" || callName == "memset" || callName == "memmove") && call_inst->getNumArgOperands() > 1){
								Value* arg = (Value*)call_inst->getArgOperand(0);
								if(((Value*)arg) == *itr){
									writeState[functionName].insert(classVarToIndex[(Value*)*itr]);
                                }
							}
							else{
								calledFunction[functionName].insert(callName);
							}
						}
					}
					else if(inst->isTerminator()){
					}
				}
				if(inst -> mayReadFromMemory()){
					if(inst->getOpcode() == Instruction::Store){
						if(inst->getNumOperands() > 1 && inst->getOperand(0) == *itr){
							readState[functionName].insert(classVarToIndex[(Value*)*itr]);
						}
					}
					else if(CallInst* call_inst = dyn_cast<CallInst>(inst)){
						Function* fn = call_inst->getCalledFunction();
                        if(fn){
                            std::string callName = fn->getName();

                            if(fn->isIntrinsic() && call_inst->getNumArgOperands() > 1){
                                Value* arg = (Value*)call_inst->getArgOperand(1);
                                if(((Value*)arg) == *itr){
                                    readState[functionName].insert(classVarToIndex[(Value*)*itr]);
                                }
                            }
                            else{
                                calledFunction[functionName].insert(callName);
                            }
                        }
					}
					else{
						readState[functionName].insert(classVarToIndex[(Value*)*itr]);
					}
				}
			}
		}
	}
    // writeUseDef();
}

std::list<Value*> UseDef::setClassVariables(Function* F, std::string contractName)
{
	//todo: file path for writing state, read contract/class name from file, do for read state also

	std::string functionName = getFunctionName(F);
	functionNames.insert(functionName);
	std::list<Value*> classVar;
    std::list<Value*> classVarCopy;
	std::map<Value*, int> classVarToIndex;
	std::map<Value*, Value*> classVarParent;
	std::list<Value*> classVarUsers;

    contract_name = contractName;

    if(functionName.find("main") == std::string::npos && !F->isIntrinsic() && F->getName().str().find(contractName) != std::string::npos && functionName != contractName){
		for(Function::iterator bb = F->begin(); bb != F->end(); ++bb){
			for(BasicBlock::iterator i = bb->begin(); i != bb->end(); ++i){

                Instruction* inst = dyn_cast<Instruction>(i);

                if(functionName == "vote")
                    outs() << *inst << '\n';

                if(AllocaInst* alloc = dyn_cast<AllocaInst>(inst)){

                }

				if(inst->getOpcode() == Instruction::GetElementPtr) {
                //gep argument must be %class.
					if(inst->getNumOperands() == 3){
						Value* v = (Value*)inst->getOperand(0);
						Type* t = v->getType();
						if(t->isPointerTy()){
							Type* t2 = ((PointerType*)t)->getElementType();
							if(t2->isStructTy()){
								StringRef name = t2->getStructName();
								std::string className = contractName;
                                if(name.str().find(className) != std::string::npos){
                                    if(name.str().find("struct") != std::string::npos){
                                        Value* index = inst->getOperand(0);
                                        // if (ConstantInt* CI = dyn_cast<ConstantInt>(index)){
                                        //     if (CI->getBitWidth() <= 64) {
                                        //         classVar.push_back((Value*)&*inst);
                                        //         classVarParent[(Value*)&*inst] = nullptr;
                                        //         classVarToIndex[(Value*)&*inst] = CI->getSExtValue();
                                        //     }
                                        // }
                                            classVar.push_back((Value*)&*inst);
                                            classVarParent[(Value*)&*inst] = index;
                                            if(classVarToIndex.find(index) != classVarToIndex.end())
                                                classVarToIndex[(Value*)&*inst] = classVarToIndex[index];
                                        // }
                                    }
                                    else{
                                        Value* index = inst->getOperand(2);
                                        if (ConstantInt* CI = dyn_cast<ConstantInt>(index)){
                                            if (CI->getBitWidth() <= 64) {
                                                classVar.push_back((Value*)&*inst);
                                                classVarParent[(Value*)&*inst] = nullptr;
                                                classVarToIndex[(Value*)&*inst] = CI->getSExtValue();
                                            }
                                        }
                                    }
								}
							}
						}
					}
				}
				else if(CallInst* call_inst = dyn_cast<CallInst>(inst)){
					Function* fn = call_inst->getCalledFunction();
					if(fn != NULL){
						std::string callName = getFunctionName(fn);
						calledFunction[functionName].insert(callName);
					}
				}
			}
			//users of all these class var also in class var, then if these classvars
			//are used as destination in store or memcpy as destination
		}

		classVarUsers = getAllUsers(F, classVar, classVarParent);
        setState(F, classVarUsers, classVarParent, classVarToIndex);
	}
	// std::list<Value*> classVarUsers;
	// classVarUsers = getAllUsers(F, classVar);
	return classVarUsers;
}

void UseDef::writeUseDef()
{
	// std::string path = "/home/namrata/writeState.txt";
	// file.open(path, std::ios::app | std::ios::out);
	bool change;
	do{
		change = false;
		for(auto funcItr = functionNames.begin(); funcItr != functionNames.end(); ++funcItr)
		{
			for(auto itr = calledFunction[*funcItr].begin(); itr != calledFunction[*funcItr].end(); ++itr)
			{
				// outs() << *funcItr << ":" << *itr << "\n";
				if(find(functionNames.begin(), functionNames.end(), *itr) != functionNames.end())
				{
					int prevSize = readState[*funcItr].size() + writeState[*funcItr].size();
					readState[*funcItr].insert(readState[*itr].begin(), readState[*itr].end());
					writeState[*funcItr].insert(writeState[*itr].begin(), writeState[*itr].end());
					if(prevSize != readState[*funcItr].size() + writeState[*funcItr].size()){
						change = true;
					}
				}
			}
		}
	}while(change);
}

std::list<llvm::Value*> UseDef::getClassVariables(Function* f)
{
	if(f)
        return functionClassVariables[f];
    else return std::list<llvm::Value*>();
}

std::string UseDef::getFunctionName(Function* f)
{
    if(f != NULL)
    {
        if(DISubprogram *di = f->getSubprogram())
        {
            std::string name = di->getName();
            return name;
        }
    }
    return "";
}

void UseDef::setClassUseDef(Module* M, std::string contractName)
{
    // Run analysis on each function
    for (Module::iterator MI = M->begin(), ME = M->end(); MI != ME; ++MI) {
		// std::string name = getFunctionName(&*MI);
        functionClassVariables[&*MI] = setClassVariables(&*MI, contractName);
	}
	writeUseDef();
    return;
}

std::map<std::string, std::set<unsigned>> UseDef::getReadState(){
    return readState;
}

std::map<std::string, std::set<unsigned>> UseDef::getWriteState(){
    return writeState;
}

std::map<llvm::Function*, std::list<Value*>> UseDef::getFunctionClassVariables(){
	return functionClassVariables;
}
