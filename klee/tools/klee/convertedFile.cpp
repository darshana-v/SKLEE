#include <cassert>
#include <klee/klee.h>
#include "types.h"
#include "functions.h"
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

class  Ballot : virtual public address { 

public:
struct  Voter { 
uint64  weight ; 
bool  voted ; 
address  delegate ; 
uint64  vote ; 
Voter(){};
Voter(uint64  weight  , bool  voted  , address  delegate  , uint64  vote  ){
this->weight=weight;
this->voted=voted;
this->delegate=delegate;
this->vote=vote;
}
};
public:
struct  Proposal { 
bytes  name ; 
uint64  voteCount ; 
Proposal(){};
Proposal(bytes  name  , uint64  voteCount  ){
this->voteCount=voteCount;
}
};
public:
address  chairperson ; 

public:
std::map < address  , Voter > voters ; 

public:
struct Vector < Proposal > proposals ; 
public:
Ballot( struct Vector < bytes  > proposalNames ) { 
chairperson = msgSender ; 
voters [ chairperson ] . weight = 1 ; 
for ( uint64  i = 0 ; 
i < proposalNames .size() ; 
i ++ ) { 
proposals . push_back ( Proposal ( proposalNames [ i ] , 0 ) ) ; 
} 
} 

public:
void giveRightToVote ( address  voter ) { 
assert ( msgSender == chairperson && "Only chairperson can give right to vote." ) ; 
assert ( ! voters [ voter ] . voted && "The voter already voted." ) ; 
assert ( voters [ voter ] . weight == 0 ) ; 
voters [ voter ] . weight = 1 ; 
} 

public:
void delegate ( address  to ) { 
Voter sender = voters [ msgSender ] ; 
assert ( ! sender . voted && "You already voted." ) ; 
assert ( to != msgSender && "Self-delegation is disallowed." ) ; 
while ( voters [ to ] . delegate != address  ( 0 ) ) { 
to = voters [ to ] . delegate ; 
assert ( to != msgSender && "Found loop in delegation." ) ; 
} 
sender . voted = true ; 
sender . delegate = to ; 
Voter delegate_ = voters [ to ] ; 
if ( delegate_ . voted ) { 
proposals [ delegate_ . vote ] . voteCount += sender . weight ; 
} 
else { 
delegate_ . weight += sender . weight ; 
} 
} 

public:
void vote ( uint64  proposal ) { 
Voter sender = voters [ msgSender ] ; 
assert ( sender . weight != 0 && "Has no right to vote" ) ; 
assert ( ! sender . voted && "Already voted." ) ; 
sender . voted = true ; 
sender . vote = proposal ; 
proposals [ proposal ] . voteCount += sender . weight ; 
} 

public:
uint64  winningProposal ( ) { 
uint64  winningProposal_ ; 
uint64  winningVoteCount = 0 ; 
for ( uint64  p = 0 ; 
p < proposals .size() ; 
p ++ ) { 
if ( proposals [ p ] . voteCount > winningVoteCount ) { 
winningVoteCount = proposals [ p ] . voteCount ; 
winningProposal_ = p ; 
} 
} 
return  winningProposal_ ; 
} 

public:
bytes  winnerName ( ) { 
bytes  winnerName_ ; 
winnerName_ = proposals [ winningProposal ( ) ] . name ; 
return  winnerName_ ; 
} 

public:
Ballot(const char addr[43]){};
Ballot(address addr){}
public:
Ballot(){};

};

int main(){ 

Ballot Object;
address  chairperson;
klee_make_symbolic(&chairperson, sizeof(chairperson), "chairperson");
Object.chairperson = chairperson;
address  voter;
klee_make_symbolic(&voter, sizeof(voter), "voter");
address  to;
klee_make_symbolic(&to, sizeof(to), "to");
uint64  proposal;
klee_make_symbolic(&proposal, sizeof(proposal), "proposal");
Object.giveRightToVote(voter);
Object.delegate(to);
Object.vote(proposal);
Object.winningProposal();
Object.winnerName();

return 0;
}
