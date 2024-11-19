#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;

//global constants
const int MAXWORDS = 8000;
const int MAXUSERLEN = 100;
const int ALPHASIZE = 26;
const char WORDFILENAME[] = "words.txt";

//runs one round of gameplay
int runOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum)
{
    if(nWords <= 0 || wordnum < 0 || wordnum >= nWords) return -1; //valid parameters check
    int stars = 0, planets = 0;
    //outline
    //while not found target word
    //ask for trial word and get input
    //process input, if not valid output correct message and continue
    //if valid input, calculate stars and planets
    //if stars is NOT target word length, then cout stars and planets
    //else break
    int n = strlen(words[wordnum]);
    int attempts = 0;
    cerr << n << " " << words[wordnum] << endl; //so i don't go insane trying to play-test this game =D
    while(true)
    {
        stars = 0; planets = 0;

        //get input trial word
        char trialWord[MAXUSERLEN+1];
        cout << "Trial word: ";
        cin.getline(trialWord, MAXUSERLEN+1);

        //correct length check
        int m = strlen(trialWord);
        if(m < MINWORDLEN || m > MAXWORDLEN){
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
        //comment this out to test any string as trial word
        if(!validWord){
            cout << "I don't know that word." << endl;
            continue;
        }

        //valid input -> consider as an attempt
        //calculate stars and planets
        attempts++;

        //alphabet letter occurrence arrays
        //use to calculate planets later on
        int alphaTrial[ALPHASIZE] = {}, alphaTarget[ALPHASIZE] = {};
        for(int i=0; i<MAXWORDLEN; i++){
            //increase occurrences if valid letter
            if(isalpha(trialWord[i])) alphaTrial[trialWord[i] - 'a']++;
            if(isalpha(words[wordnum][i]))alphaTarget[words[wordnum][i] - 'a']++;
        }

        //every star is a planet
        for(int i=0; i<MAXWORDLEN; i++){
            if(trialWord[i] == words[wordnum][i] && trialWord[i] != '\0'){
                //found star
                //star takes priority over planet, decrease occurrences
                alphaTrial[trialWord[i] - 'a']--;
                alphaTarget[words[wordnum][i] - 'a']--;
                stars++;
            }
        }
        if(stars == n && m == n) break; //user found target word

        //calculate planets with occurrence arrays
        for(int i=0; i<26; i++){
            planets += min(alphaTrial[i], alphaTarget[i]);
        }

        cout << "Stars: " << stars << ", Planets: " << planets << endl;
    }
    return attempts;
}

//main loop
int main()
{
    //load word bank and check that it's not empty
    char w[MAXWORDS][MAXWORDLEN+1];
    int n = getWords(w, MAXWORDS, WORDFILENAME);
    if(n < 1){
        cout << "No words were loaded, so I can't play the game." << endl;
        return 0;
    }

    //get user input for # of rounds
    cout << "How many rounds do you want to play? ";
    int rounds; cin >> rounds;
    if(rounds <= 0){
        cout << "The number of rounds must be positive." << endl;
        return 0;
    }

    double total = 0.0; //stores total attempts over all rounds
    int min = -1, max = -1;
    //so we can get user input smoothly
    cin.ignore(10000, '\n');

    //play rounds of game
    for(int i=1; i<=rounds; i++){
        //print round info
        //get random target word
        cout << endl;
        cout << "Round " << i << endl;
        int idx = randInt(0, n-1);
        int targetWordLen = strlen(w[idx]);
        cout << "The secret word is " << targetWordLen << " letters long." << endl;
        int attempts = runOneRound(w, n, idx); //carries out round
        
        //round attempts message
        if(attempts == 1){
            cout << "You got it in 1 try." << endl;
        }
        else{
            cout << "You got it in " << attempts << " tries." << endl;
        }

        if(min < 0) min = attempts; //so that min doesn't stay -1 forever
        else if(attempts < min) min = attempts;
        
        if(attempts > max) max = attempts;

        //calculate and print statistics
        total += attempts;
        cout << "Average: " << fixed << setprecision(2) << total/i << ", ";
        cout << "minimum: " << min << ", maximum: " << max << endl;
    }
}