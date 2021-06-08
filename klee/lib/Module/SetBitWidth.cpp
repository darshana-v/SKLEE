//===-- SetBitWidth.cpp ----------------------------------------------===//
//
//                     The KLEE Symbolic Virtual Machine
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Passes.h"

#include "klee/Config/Version.h"
#include "llvm/Analysis/MemoryBuiltins.h"
#include "llvm/Analysis/ConstantFolding.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/Pass.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/DebugInfoMetadata.h"

#include <string>


using namespace llvm;

namespace klee {

char SetBitWidth::ID;

bool SetBitWidth::runOnModule(Module &M) {
    bool dirty = false;
    for (Module::iterator f = M.begin(), fe = M.end(); f != fe; ++f)
    // for (Function::iterator b = f->begin(), be = f->end(); b != be; ++b)
        dirty |= runOnFunction(&*f, M);

      // if (Function *Declare = M.getFunction("llvm.trap")) {
      //   Declare->eraseFromParent();
      //   dirty = true;
      // }
    return dirty;
}

bool SetBitWidth::runOnFunction(Function* f, Module &M) {

    bool dirty = false;
    std::string funcName = f->getName().str();
    if(funcName.find("main") != std::string::npos){
        LLVMContext &ctx = M.getContext();

        // unsigned WordSize = DataLayout.getPointerSizeInBits() / 8;

        for (Function::iterator b = f->begin(), be = f->end(); b != be; ++b){
            for (BasicBlock::iterator i = b->begin(), ie = b->end(); i != ie;){
                IntrinsicInst *inst = dyn_cast<IntrinsicInst>(&*i);

            // increment now since deletion of instructions makes iterator invalid.
                ++i;

                if (inst) {
                    if (DbgDeclareInst *dbg = dyn_cast<DbgDeclareInst>(inst)){
                        if (AllocaInst *dbgAI = dyn_cast<AllocaInst>(dbg->getAddress())){
                            // outs() << *dbgAI << "\n";
                            if (DILocalVariable *varMD = dbg->getVariable()){ // probably not needed?
                                // outs() << *inst << ":" << varMD->getName().str() << "\n";
                                llvm::IRBuilder<> Builder(inst);
                                Value *dst = inst->getArgOperand(0);
                                Value *src = inst->getArgOperand(1);
                            }
                        }
                    }
                }
            }
        }
    }
    return dirty;
}
} // namespace klee
