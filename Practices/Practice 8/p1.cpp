#include <iostream>
using namespace std;
#define NUM_BUCK 10

class ClosedHashTable{
    public:
        void insert(int idNum);
        bool search(int idNum) const;
        void output() const;
    
    private:
        inline int hashFunc(int idNum) const{
            return (idNum % NUM_BUCK); // modulo 10
        }
        struct BUCKET{
            int idNum;
            bool used;
            BUCKET() {used = false; idNum = -1;}
        };
        BUCKET m_buckets[NUM_BUCK];
};

void ClosedHashTable::insert(int idNum) {
    int bucket = hashFunc(idNum);
    for(int tries = 0; tries<NUM_BUCK; tries++){
        if(!m_buckets[bucket].used){
            m_buckets[bucket].idNum = idNum;
            m_buckets[bucket].used = true;
            return;
        }
        bucket = (bucket + 1) % NUM_BUCK;
    }
    cout << "no room left in hash table!!!" << endl;
}

bool ClosedHashTable::search(int idNum) const {
    int bucket = hashFunc(idNum);
    for(int tries=0; tries<NUM_BUCK; tries++){
        if(!m_buckets[bucket].used)
            return false;
        if(m_buckets[bucket].idNum == idNum)
            return true;
        bucket = (bucket + 1) % NUM_BUCK;
    }
    return false; //idNum is not in the hash table
}

void ClosedHashTable::output() const {
    for(int i=0; i<NUM_BUCK; i++){
        cout << m_buckets[i].idNum << " ";
    }
    cout << endl;
}

int main() {
    ClosedHashTable cht;

    for(int i=0; i<8; i++)
        cht.insert(i+10);
    cht.output();

    for(int i=0;i<4;i++)
        cht.insert(i+20);
    cht.output();

    if(cht.search(23))
        cout << "23 is in the hash table." << endl;
}