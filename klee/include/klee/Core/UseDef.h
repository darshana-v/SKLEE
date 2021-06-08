#ifndef USEDEF
#define USEDEF

#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <llvm/ADT/BitVector.h>

#include "klee/Core/defs.h"

namespace llvm {
  class BasicBlock;
  class BranchInst;
  class CallInst;
  class Constant;
  class ConstantExpr;
  class Function;
  // class GlobalValue;
  class Instruction;
  // class LLVMContext;
  // class DataLayout;
  // class Twine;
  class Value;
  class BitVector;
}

namespace klee{
    class UseDef{

    public:
        std::ofstream file;
        std::set<std::string> functionNames;
        std::map<std::string, std::set<unsigned>> readState;
        std::map<std::string, std::set<unsigned>> writeState;
        std::map<std::string, std::set<std::string>> calledFunction;
        std::map<llvm::Function*, std::list<llvm::Value*>> functionClassVariables;

        UseDef();
        int indexFind(llvm::Value* var, std::map<llvm::Value*, llvm::Value*> &parent, std::map<llvm::Value*, int> &index);
        // void addVars(llvm::Value* var, std::list<llvm::Value*> &classVar, std::map<llvm::Value*, llvm::Value*> &classVarParent);
        std::list<llvm::Value*> setClassVariables(llvm::Function* F, std::string contractName);
        std::list<llvm::Value*> getClassVariables(llvm::Function* f);
        void writeUseDef();
        std::string getFunctionName(llvm::Function* f);
        void setClassUseDef(llvm::Module* m, std::string contractName);
        std::map<std::string, std::set<unsigned>> getReadState();
        std::map<std::string, std::set<unsigned>> getWriteState();

        std::list<llvm::Value*> getAllUsers(llvm::Function* f, std::list<llvm::Value*> classVar, std::map<llvm::Value*, llvm::Value*>& classVarParent);
        llvm::BitVector setUsers(llvm::Function* f, llvm::BitVector prev, std::vector<void*> domain, std::map<void*, int>domainToIndex, std::map<llvm::Value*, llvm::Value*>& clasVarParent);
        void setState(llvm::Function* f, std::list<llvm::Value*>& classVar, std::map<llvm::Value*, llvm::Value*>& classVarParent, std::map<llvm::Value*, int>& classVarToIndex);

        void printValue(llvm::Value* v);
        void printVector(std::vector<llvm::Value*> vec);
        void printList(std::list<llvm::Value*> li);
        std::map<llvm::Function*, std::list<llvm::Value*>> getFunctionClassVariables();
    };
    // extern UseDef* globalUseDef;
}

#endif
