#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;

const int MAXWORDS = 8000;
const char WORDFILENAME[] = "words.txt";

int runOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum)
{
    if(nWords <= 0 || wordnum < 0 || wordnum >= nWords) return -1;
    int stars, planets;
    //while stars is not the length of the target word:
    //ask for trial word and get input
    //process input, if not valid output correct message and continue
    //if valid input, calculate stars and planets
    //if stars is NOT target word length, then cout stars and planets
    //else break
    int n = strlen(words[wordnum]);
    int attempts = 0;
    cout << "The secret word is " << n << " letters long." << endl;
    cout << n << " " << words[wordnum] << endl;
    while(stars != n)
    {
        stars = 0; planets = 0;

        char trialWord[101];
        cout << "Trial word: ";
        cin >> trialWord;
        cout << "word: " << trialWord << endl;

        //correct length check
        int m = strlen(trialWord);
        if(m < 4 || m > 6){
            cout << "Your trial word must be a word of 4 to 6 lower case letters." << endl;
            continue;
        }

        //correct syntax (lowercase letters) check
        bool validSyntax = true;
        for(int i=0; i<m; i++){
            if(!islower(trialWord[i])){
                cout << "Your trial word must be a word of 4 to 6 lower case letters." << endl;
                validSyntax = false;
                break;
            }
        }
        if(!validSyntax) continue;

        //valid word in bank check
        bool validWord = false;
        for(int i=0; i<nWords; i++){
            if(strcmp(trialWord, words[i]) == 0){
                validWord = true;
                break;
            }
        }
        // if(!validWord){
        //     cout << "I don't know that word." << endl;
        //     continue;
        // }

        //valid input -> consider as an attempt
        //calculate stars and planets
        attempts++;

        int alphaTrial[27] = {}, alphaTarget[27] = {};
        for(int i=0; i<MAXWORDLEN; i++){
            alphaTrial[trialWord[i] - 'a']++;
            alphaTarget[words[wordnum][i] - 'a']++;
        }

        //every star is a planet
        for(int i=0; i<MAXWORDLEN; i++){
            if(trialWord[i] == words[wordnum][i] && trialWord[i] != '\0'){
                //found star
                // cout << "Star at " << i << " " << trialWord[i] << " same as " << words[wordnum][i] << endl;
                alphaTrial[trialWord[i] - 'a']--;
                alphaTarget[words[wordnum][i] - 'a']--;
                stars++;
            }
        }
        if(stars == n) break;

        for(int i=0; i<26; i++){
            planets += min(alphaTrial[i], alphaTarget[i]);
        }

        cout << "Stars: " << stars << ", Planets: " << planets << endl;
    }
    // cout << n << " " << words[wordnum] << endl;
    // int input; cin >> input;
    return attempts;
}

int main()
{
    char w[MAXWORDS][MAXWORDLEN+1];
    int n = getWords(w, MAXWORDS, WORDFILENAME);
    if(n < 1){
        cout << "No words were loaded, so I can't play the game." << endl;
        return 0;
    }

    cout << "How many rounds do you want to play? ";
    int rounds; cin >> rounds;
    if(rounds <= 0){
        cout << "The number of rounds must be positive." << endl;
        return 0;
    }

    double total = 0.0;
    int min = -1, max = -1;
    cin.ignore(10000, '\n');

    //play rounds of game
    for(int i=1; i<=rounds; i++){
        cout << endl;
        cout << "Round " << i << endl;
        int idx = randInt(0, n-1);
        int attempts = runOneRound(w, n, idx);
        
        if(attempts == 1){
            cout << "You got it in 1 try." << endl;
        }
        else{
            cout << "You got it in " << attempts << " tries." << endl;
        }

        if(min < 0) min = attempts;
        else if(attempts < min) min = attempts;
        
        if(attempts > max) max = attempts;

        total += attempts;
        cout << "Average: " << fixed << setprecision(2) << total/i << ", ";
        cout << "minimum: " << min << ", maximum: " << max << endl;
    }
}