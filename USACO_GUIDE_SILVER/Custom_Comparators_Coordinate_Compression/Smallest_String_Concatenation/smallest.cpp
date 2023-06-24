#include <bits/stdc++.h>
using namespace std;

struct Word{
    string word;
};

bool cmp (Word& a, Word& b){
    //put word a before word b if a+b < b+a lexographically
    //intuition is to think of words as base 26 numbers
    //and in order to accurately compare two words
    //the sizes of the words must be the same
    //this is ensured since a+b has same size as b+a
    return (a.word + b.word < b.word + a.word);
}

int main(){
    //freopen("smallest.in" , "r" , stdin);

    int n; cin >> n;
    vector<Word> words(n);
    for(int i=0; i<n; i++){
        cin >> words[i].word;
    }
    sort(words.begin() , words.end() , cmp);

    for(int i=0; i<n; i++){
        cout << words[i].word;
    }

    return 0;
}

/*
 * NOTES
 * finding the right comparison operator can greatly help sorting
 * note that when comparing two words we can consider them to be consecutive
 * even if they aren't, using a greedy alg approach we can focus on just a and b
 * it is better to choose the smaller of a+b and b+a to be in the final string
 * so this is still a valid comparison to use
 */