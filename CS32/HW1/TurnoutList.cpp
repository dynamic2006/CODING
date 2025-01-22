#include "TurnoutList.h"

TurnoutList::TurnoutList()
{
}

bool TurnoutList::add(unsigned long turnout)
{
    if(0 <= turnout && turnout <= 1800){
        s.insert(turnout);
        return true;
    }
    return false;
}

bool TurnoutList::remove(unsigned long turnout)
{
    return s.erase(s.find(turnout));
}

int TurnoutList::size() const
{
    return s.size();
}

unsigned long TurnoutList::minimum() const
{
    unsigned long minval = NO_TURNOUTS;
    for(int i=0; i<s.size(); i++){
        unsigned long cur; s.get(i, cur);
        if(cur < minval) minval = cur;
    }
    return minval;
}

unsigned long TurnoutList::maximum() const
{
    unsigned long maxval = -1;
    for(int i=0; i<s.size(); i++){
        unsigned long cur; s.get(i, cur);
        if(cur > maxval) maxval = cur;
    }
    if(maxval > 0) return maxval;
    return NO_TURNOUTS;
}
