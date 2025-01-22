#include "Sequence.h"

Sequence::Sequence()
{
    n = 0;
}

const bool Sequence::empty()
{
    return !n;
}

const int Sequence::size()
{
    return n;
}

int Sequence::insert(int pos, const ItemType &value)
{
    if(size() >= DEFAULT_MAX_ITEMS || pos < 0 || pos > size()) return -1;
    for(int i=size(); i>pos; i--) seq[i] = seq[i-1];
    seq[pos] = value; n++;
    return pos;
}

int Sequence::insert(const ItemType &value)
{
    if(size() >= DEFAULT_MAX_ITEMS) return -1;
    for(int i=0; i<size(); i++){
        if(value <= seq[i]) return insert(i, value);
    }
    return insert(size(), value);
}

bool Sequence::erase(int pos)
{
    if(pos < 0 || pos >= size()) return false;
    for(int i=pos; i<size()-1; i++) seq[i] = seq[i+1];
    n--;
    return true;
}

int Sequence::remove(const ItemType &value)
{
    int counter = 0;
    for(int i=size()-1; i>=0; i--){
        if(seq[i] == value){
            erase(i);
            counter++;
        }
    }
    return counter;
}

const bool Sequence::get(int pos, ItemType &value)
{
    if(pos < 0 || pos >= size()) return false;
    value = seq[pos]; return true;
}

bool Sequence::set(int pos, const ItemType &value)
{
    if(pos < 0 || pos >= size()) return false;
    seq[pos] = value; return true;
}

const int Sequence::find(const ItemType &value)
{
    for(int i=0; i<size(); i++){
        if(seq[i] == value) return i;
    }
    return -1;
}

void Sequence::swap(Sequence &other)
{
    for(int i=0; i<DEFAULT_MAX_ITEMS; i++){
        ItemType temp = other.seq[i];
        other.seq[i] = seq[i];
        seq[i] = temp;
    }
    int tn = other.n;
    other.n = n;
    n = tn;
}
