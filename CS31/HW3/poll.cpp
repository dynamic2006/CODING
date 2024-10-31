#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//checks if char c is a party code
bool isPartyCode(char c)
{
    int diff = tolower(c) - 'a';
    if(diff >= 0 && diff <= 25) return true;
    return false;
}

//checks if char c is a digit 0-9
bool isDigit(char c)
{
    const string digs = "0123456789";
    for(int i=0; i<digs.size(); i++){
        if(c == digs[i]) return true;
    }
    return false;
}

//checks if string code is a state code
bool isStateCode(string code)
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
        "KY.LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NJ.NH.NM.NY.NC."
        "ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    for(int i=0; i<codes.size(); i+=3){
        if(toupper(code[0]) == codes[i] && toupper(code[1]) == codes[i+1]) return true;
    }
    return false;
}

//checks if pollData has correct syntax
bool hasRightSyntax(string pollData)
{
    //toggle variables
    bool partyCode = true, digit = false, stateCode = false;
    int digitCount = 0; //consecutive digits found
    string code = ""; //used for state code
    for(int i=0; i<pollData.size(); i++){
        if(partyCode){
            //if on party code state
            if(!isPartyCode(pollData[i])){
                //failed party code check
                return false;
            }
            //next look for digit
            partyCode = false;
            digit = true;
            stateCode = false;
        }
        else if(digit && isDigit(pollData[i])){
            digitCount++; //increment consecutive digits found
            if(digitCount == 2){
                //max digit count reached
                //must switch to finding stateCode 
                partyCode = false;
                digit = false;
                stateCode = true;
            }
            else{
                //next can seach for either
                //digit OR statecode
                partyCode = false;
                digit = true;
                stateCode = true;
            }
        }
        else if(stateCode){
            digitCount = 0; //reset digit count
            code += pollData[i]; //append current character to code
            if(code.size() == 2){
                if(!isStateCode(code)){
                    //failed state code check
                    return false;
                }
                //passed state code check
                //reset code and toggle party code on
                code = "";
                partyCode = true;
                digit = false;
                stateCode = false;
            }
            else{
                //still need to complete code
                //keep statecode toggled on
                partyCode = false;
                digit = false;
                stateCode = true;
            }
        }
        else{
            //didnt find vote count
            return false;
        }

    }
    if(partyCode && !digit && !stateCode){
        //all good
        return true;
    }
    return false;
}

//computes votes for a party in pollData
//alters voteCount if necesscary, returns number depending on state
int computeVotes(string pollData, char party, int& voteCount)
{
    //checks for syntax and party validity
    if(!hasRightSyntax(pollData)) return 1;
    if(!isPartyCode(party)) return 3;

    //ans is total votes for party
    //curVotes tracks current vote count
    //prevLetter tracks last seen letter
    int ans = 0, curVotes = 0;
    char prevLetter = '.';
    for(int i=0; i<pollData.size(); i++){
        if(isDigit(pollData[i])){
            //convert char digits to int and store in curVotes
            curVotes *= 10;
            curVotes += (pollData[i] - '0');
        }
        else{
            if(i>0 && isDigit(pollData[i-1]) && curVotes == 0){
                //if done computing curVotes and it's equal to zero
                return 2;
            }
            //otherwise if done computing curVotes, add to ans if party matches
            if(tolower(prevLetter) == tolower(party)) ans += curVotes;
            curVotes = 0;
            prevLetter = pollData[i];
        }
    }
    //set voteCount to ans
    voteCount = ans;
    return 0;
}

int main()
{
    assert(hasRightSyntax("R40TXD54CA"));
    assert(!hasRightSyntax("R40MXD54CA"));
    int votes;
    votes = -999;    // so we can detect whether computeVotes sets votes
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", 'd', votes) == 0 && votes == 82);
    votes = -999;    // so we can detect whether computeVotes sets votes
    assert(computeVotes("R40TXD54CA", '%', votes) == 3  &&  votes == -999);

    //custom tests
    assert(!isPartyCode('4'));
    assert(!isPartyCode('+'));
    assert(!isPartyCode('^'));

    //has right syntax checks
    assert(!hasRightSyntax("    ")); //all spaces poll data
    assert(hasRightSyntax("")); //empty string
    assert(!hasRightSyntax("R18")); //no state code
    assert(hasRightSyntax("r0tX")); //poll data with single zero digit
    assert(!hasRightSyntax("^0tx")); //party code is not letter
    assert(!hasRightSyntax("a1txb001tx")); //three digits in a row
    assert(!hasRightSyntax("atx")); //no digits found
    assert(hasRightSyntax("a0alb00ak")); //multiple zero digits
    assert(!hasRightSyntax("R40TXD54CAr6Msd28nYL06UT ")); //ends with space
    assert(!hasRightSyntax("R40TXD54CAr6Msd28nYL06UTR")); //ends with party code

    //compute votes checks
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", 'l', votes) == 0 && votes == 6); //compute party votes for valid poll data
    assert(computeVotes("", 'd', votes) == 0 && votes == 0); //empty string poll data
    assert(computeVotes("", '[', votes) == 3 && votes == 0); //invalid party code
    assert(computeVotes("   ", 'r', votes) == 1 && votes == 0); //all spaces (invalid) poll data
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", 'a', votes) == 0 && votes == 0); //party not found in poll data
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", ' ', votes) == 3 && votes == 0); //party code is space character
    assert(computeVotes("R0TXD54CAr6Msd28nYL06UT", 'r', votes) == 2 && votes == 0); //party gets zero votes
    assert(computeVotes("R18", 'r', votes) == 1 && votes == 0); //invalid poll data syntax
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", 'd', votes) == 0 && votes == 82); //sample data test
    assert(computeVotes("a01alb01ak", 'a', votes) == 0 && votes == 1); //some zeros but no nonzero vote counts

    //other checks
    assert(computeVotes("", 'd', votes) == 0);
    assert(computeVotes("", '@', votes) == 3);
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", 'l', votes) == 0 && votes == 6);
    assert(!hasRightSyntax("R408TXD54CAr6Msd28nYL06UT"));
    assert(!hasRightSyntax("R40TX:D54CA"));
    assert(!hasRightSyntax("R40TX D54CA"));
    assert(computeVotes("R40TXD54CAr6Msd28nYL06UT", 'n', votes) == 0 && votes == 0);
    assert(computeVotes("R0TXD54CAr6Msd28nYL06UT", 'd', votes) == 2);
    assert((computeVotes("R00TXD54CAr6Msd28nYL06UT", 'd', votes) == 2) && votes == 0);

    cout << "all tests passed" << endl;
}