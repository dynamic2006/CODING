#include "newSequence.h"

Sequence::Sequence(int n)
{
    this->n = n;
    seq = new ItemType[n];
}

Sequence::~Sequence()
{
    delete[] seq;
}

//deep-copy -- check if we r supposed to do shallow cpy instead
Sequence::Sequence(const Sequence &other)
{
    this->n = other.n;
    seq = new ItemType[n];
    for(int i=0; i<n; i++) seq[i] = other.seq[i];
}

Sequence& Sequence::operator=(const Sequence& other)
{
    delete[] seq;
    this->n = other.n;
    seq = new ItemType[n];
    for(int i=0; i<n; i++) seq[i] = other.seq[i];
    return *this;
}

bool Sequence::empty() const
{
    return !n;
}

int Sequence::size() const
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

bool Sequence::get(int pos, ItemType &value) const
{
    if(pos < 0 || pos >= size()) return false;
    value = seq[pos]; return true;
}

bool Sequence::set(int pos, const ItemType &value)
{
    if(pos < 0 || pos >= size()) return false;
    seq[pos] = value; return true;
}

int Sequence::find(const ItemType &value) const
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
