#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int evaluate(string infix, const bool values[], string& postfix, bool& result)
{
    //accumulate and check if infix is valid
    postfix = "";
    char prev = '(';
    int openPars = 0;
    stack<char> acc;

    cout << "HERE" << endl;
    for(int i=0; i<infix.size(); i++){
        char c = infix[i];
        if(c == ' ') continue;
        if(isdigit(c)){
            if(prev != '(' && prev != '!' && prev != '&' && prev != '|') return 1;
            postfix += c;
            prev = c;
            continue;
        }
        switch(c){
            case '(':
                cout << "OPENPAR" << endl;
                if(prev != '(' && prev != '!' && prev != '&' && prev != '|') return 1;
                openPars++;
                acc.push(c);
                break;
            case ')':
                cout << "CLOSEPAR" << endl;
                if(!isdigit(prev) && prev != ')') return 1;
                if(openPars <= 0) return 1;
                openPars--;
                while(acc.top() != '('){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.pop();
                break;
            case '!':
                cout << "EXCLAM" << endl;
                if(prev != '(' && prev != '!' && prev != '&' && prev != '|') return 1;
                //NOTE: USING OPPOSITE: c >= stack top using ASCII
                //MAY NOT WORK, CHECK THIS!!!
                while(!acc.empty() && acc.top() != '(' && c >= acc.top()){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.push(c);
                break;
            case '&':
                cout << "AMPERSAND" << endl;
                if(prev != ')' && !isdigit(prev)) return 1;
                while(!acc.empty() && acc.top() != '(' && c >= acc.top()){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.push(c);
                break;
            case '|':
                cout << "OR" << endl;
                if(prev != ')' && !isdigit(prev)) return 1;
                while(!acc.empty() && acc.top() != '(' && c >= acc.top()){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.push(c);
                break;
            default:
                cout << "WTF" << endl;
                return 1;
        }
        prev = c;
    }
    // cout << "ERE" << endl;
    if(openPars > 0) return 1;

    //build postfix
    while(!acc.empty()){
        postfix += acc.top();
        acc.pop();
    }
    cout << "POSTFIX " << postfix << endl;

    //evaluate postfix expression
    stack<bool> operands;
    for(int i=0; i<postfix.size(); i++){
        char c = postfix[i];
        if(isdigit(c)){
            operands.push(values[c - '0']);
        }
        else if(c == '!'){
            bool op = operands.top(); operands.pop();
            operands.push(!op);
        }
        else{
            bool op2 = operands.top(); operands.pop();
            bool op1 = operands.top(); operands.pop();
            if(c == '&'){
                operands.push(op1 & op2);
            }
            else{
                operands.push(op1 | op2);
            }
            
        }
    }
    cout << "SIZE " << operands.size() << endl;
    if(operands.size() == 1){
        result = operands.top(); operands.pop();
        return 0;
    }
    return 1;
}

int main()
{
    bool ba[10] = {
        //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    string pf;
    bool answer;
    evaluate("2| 3", ba, pf, answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(evaluate("8|", ba, pf, answer) == 1);
    cout << "OK" << endl;
    assert(evaluate(" &6", ba, pf, answer) == 1);
    assert(evaluate("4 5", ba, pf, answer) == 1);
    assert(evaluate("01", ba, pf, answer) == 1);
    assert(evaluate("()", ba, pf, answer) == 1);
    assert(evaluate("()4", ba, pf, answer) == 1);
    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
    assert(evaluate("2(&8)", ba, pf, answer) == 1);
    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
    assert(evaluate("x+5", ba, pf, answer) == 1);
    assert(evaluate("2|3|4", ba, pf, answer) == 0
                            &&  pf == "23|4|"  &&  answer);
    assert(evaluate("2|(3|4)", ba, pf, answer) == 0
                            &&  pf == "234||"  &&  answer);
    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
                            &&  pf == "43!03&&|"  &&  !answer);
    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
    assert(evaluate("((6))", ba, pf, answer) == 0  &&  pf == "6"  &&  answer);
    ba[2] = false;
    ba[9] = true;
    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
    cout << "Passed all tests" << endl;
}