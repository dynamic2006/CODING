#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluate(string infix, const bool values[], string& postfix, bool& result)
{
    //accumulate and check if infix is valid
    postfix = "";
    char prev = '(';
    int openPars = 0;
    stack<char> acc;

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
                if(prev != '(' && prev != '!' && prev != '&' && prev != '|') return 1;
                openPars++;
                acc.push(c);
                break;
            case ')':
                if(!isdigit(prev) && prev != ')') return 1;
                if(acc.empty() || openPars <= 0) return 1;
                openPars--;
                while(acc.top() != '('){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.pop();
                break;
            case '!':
                if(prev != '(' && prev != '!' && prev != '&' && prev != '|') return 1;
                //NOTE: USING OPPOSITE: c >= stack top using ASCII
                //MAY NOT WORK, CHECK THIS!!!
                while(!acc.empty() && acc.top() != '(' && c > acc.top()){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.push(c);
                break;
            case '&':
                if(prev != ')' && !isdigit(prev)) return 1;
                while(!acc.empty() && acc.top() != '(' && c >= acc.top()){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.push(c);
                break;
            case '|':
                if(prev != ')' && !isdigit(prev)) return 1;
                while(!acc.empty() && acc.top() != '(' && c >= acc.top()){
                    postfix += acc.top();
                    acc.pop();
                }
                acc.push(c);
                break;
            default:
                return 1;
        }
        prev = c;
    }
    if(openPars > 0) return 1;
    if(!isdigit(prev) && prev != ')') return 1;

    //build postfix
    // cout << "PREPOSTFIX " << postfix << endl;
    while(!acc.empty()){
        postfix += acc.top();
        acc.pop();
    }
    // cout << "VALID INFIX OF " << infix << " CONVERTED TO POSTFIX " << postfix << endl;

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

    if(operands.size() == 1){
        result = operands.top(); operands.pop();
        return 0;
    }
    return 1;
}