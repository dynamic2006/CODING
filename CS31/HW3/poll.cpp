#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool isPartyCode(char c)
{
    int diff = tolower(c) - 'a';
    if(diff >= 0 && diff <= 25) return true;
    return false;
}

bool isDigit(char c)
{
    const string digs = "0123456789";
    for(int i=0; i<digs.size(); i++){
        if(c == digs[i]) return true;
    }
    return false;
}

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

bool hasRightSyntax(string pollData)
{
    // cout << "IN LOOP" << endl;
    //code
    bool partyCode = true, digit = false, stateCode = false;
    int digitCount = 0;
    string code = "";
    for(int i=0; i<pollData.size(); i++){
        // cout << "IN LOOP" << endl;
        if(partyCode){
            if(!isPartyCode(pollData[i])){
                // cout << "Failed party code check" << endl;
                return false;
            }
            partyCode = false;
            digit = true;
            stateCode = false;
        }
        else if(digit && isDigit(pollData[i])){
            digitCount++;
            if(digitCount == 2){
                partyCode = false;
                digit = false;
                stateCode = true;
            }
            else{
                partyCode = false;
                digit = true;
                stateCode = true;
            }
        }
        else if(stateCode){
            code += pollData[i];
            if(code.size() == 2){
                if(!isStateCode(code)){
                    // cout << "Failed State Code check at " << i << endl;
                    return false;
                }
                code = "";
                partyCode = true;
                digit = false;
                stateCode = false;
            }
            else{
                partyCode = false;
                digit = false;
                stateCode = true;
            }
        }
        else{
            // cout << "Likely didn't find vote count" << endl;
            return false;
        }

    }
    // cout << partyCode << " " << digit << " " << stateCode << endl;
    if(partyCode && !digit && !stateCode){
        // cout << "All Good!" << endl;
        return true;
    }
    // cout << partyCode << " " << digit << stateCode << endl;
    return false;
}

int computeVotes(string pollData, char party, int& voteCount)
{
    //code
    // cout << "IN LOOP" << endl;
    if(!hasRightSyntax(pollData)) return 1;
    if(!isPartyCode(party)) return 3;

    int ans = 0, curVotes = -1;
    char c = '.';
    // cout << "IN LOOP" << endl;
    for(int i=0; i<pollData.size(); i++){
        if(isDigit(pollData[i])){
            curVotes *= 10;
            curVotes += (pollData[i] - '0');
        }
        else{
            if(isDigit(c) && curVotes == 0){
                // cout << "BREAK AT " << i << endl;
                return 2;
            }
            if(!isDigit(c) && tolower(c) == tolower(party)) ans += curVotes;
            curVotes = 0;
            c = pollData[i];
        }
    }
    voteCount = ans;
    // cout << voteCount << endl;
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
    cout << "All tests succeeded" << endl;
}