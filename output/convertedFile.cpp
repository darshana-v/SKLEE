#include <cassert>
#include <klee/klee.h>
#include "../types.h"
#include "../functions.h"
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

class  WithdrawalContract : virtual public address { 

public:
address  richest ; 

public:
uint64  mostSent ; 

public:
std::map < address  , uint64  > pendingWithdrawals ; 
public:
WithdrawalContract ( ) { 
richest = msgSender ; 
mostSent = msgValue ; 
} 

public:
bool  becomeRichest ( ) { 
if ( msgValue > mostSent ) { 
pendingWithdrawals [ richest ] += msgValue ; 
richest = msgSender ; 
mostSent = msgValue ; 
return true ; 
} 
else { 
return false ; 
} 
} 

public:
void withdraw ( ) { 
uint64  amount = pendingWithdrawals [ msgSender ] ; 
pendingWithdrawals [ msgSender ] = 0 ; 
msgSender . transfer ( amount ) ; 
} 

public:
// Address constructor.
WithdrawalContract(const char addr[43]){};
WithdrawalContract(address addr){}
};

int main(){ 

WithdrawalContract Object;
address  richest;
klee_make_symbolic(&richest, sizeof(richest), "richest");
Object.richest = richest;
uint64  mostSent;
klee_make_symbolic(&mostSent, sizeof(mostSent), "mostSent");
Object.mostSent = mostSent;
Object.becomeRichest();
Object.withdraw();

return 0;
}
