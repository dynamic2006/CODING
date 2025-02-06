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
    cout << "VALID INFIX OF " << infix << " CONVERTED TO POSTFIX " << postfix << endl;

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

int main()
{
    bool ba[10] = {
        //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    string pf;
    bool answer;
    evaluate("2| 3", ba, pf, answer);
    assert(evaluate("", ba, pf, answer) == 1); //testing empty string
    assert(evaluate("   ", ba, pf, answer) == 1); //testing string with only blanks
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(evaluate("8|", ba, pf, answer) == 1);
    assert(evaluate(" &6", ba, pf, answer) == 1);
    assert(evaluate("8&&6", ba, pf, answer) == 1); //testing double and
    assert(evaluate("8||6", ba, pf, answer) == 1); //testing double or
    assert(evaluate("8!!6", ba, pf, answer) == 1); //testing double exclam
    assert(evaluate("8!&6", ba, pf, answer) == 1); //testing exclam before and
    assert(evaluate("8&!6", ba, pf, answer) == 0 && !answer); //testing exclam after and
    assert(evaluate("4 5", ba, pf, answer) == 1 && !answer); //testing if answer is reset for invalid
    assert(evaluate("8&&&6", ba, pf, answer) == 1); //testing triple and
    assert(evaluate("!!!!6", ba, pf, answer) == 0 && answer); //testing just exclams
    assert(evaluate("(!!!!)6", ba, pf, answer) == 1 && answer); //testing exclams with parantheses (?)
    assert(evaluate("2&!2", ba, pf, answer) == 0 && !answer); //testing logic
    assert(evaluate("2|!2", ba, pf, answer) == 0 && answer); //testing logic
    assert(evaluate("2", ba, pf, answer) == 0 && answer); //given tc
    assert(evaluate("(3)", ba, pf, answer) ==  0 && !answer); //given tc
    assert(evaluate("2&(3)", ba, pf, answer) == 0 && !answer); //given tc
    assert(evaluate("0 & !9", ba, pf, answer) == 0 && answer); //given tc
    assert(evaluate("!(7|8)", ba, pf, answer) == 0 && !answer); //given tc
    assert(evaluate("!7|8", ba, pf, answer) == 0 && answer); //given tc
    assert(evaluate("6|4&5", ba, pf, answer) == 0 && answer); //given tc
    assert(evaluate("!()", ba, pf, answer) == 1); //just exclam with paras
    assert(evaluate("!!!0&1", ba, pf, answer) == 0 && !answer); //testing precedence
    assert(evaluate("1&!(9|1&1|9) | !!!(9&1&9)", ba, pf, answer) == 0 && answer); //given test case
    assert(evaluate("!(!(!(!6)))", ba, pf, answer) == 0 && answer); //testing exclam with paras
    assert(evaluate("!(1&2&3&4)", ba, pf, answer) == 0 && answer); //testing multiple ands
    assert(evaluate("!1&2&3&4", ba, pf, answer) == 0 && !answer); //same test as before wo para
    assert(evaluate("!(!(!!6 & 6 &   8))  | ((8))", ba, pf, answer) == 0); //created tc
    assert(evaluate("   !!!6   ", ba, pf, answer) == 0 && !answer); //created tc
    assert(evaluate("6&7&!!!6", ba, pf, answer) == 0 && !answer); //tc
    assert(evaluate("6&0|!!!6", ba, pf, answer) == 0 && answer); //tc
    assert(evaluate("6&0|!!!!!!7", ba, pf, answer) == 0 && answer); //tc
    assert(evaluate(")(!6)", ba, pf, answer) == 1); //tc
    assert(evaluate("(!6))", ba, pf, answer) == 1); //tc
    assert(evaluate("((!6)", ba, pf, answer) == 1); //tc
    assert(evaluate("!(6&6&6&6)", ba, pf, answer) == 0 && !answer); //tc
    assert(evaluate("!6&6&6&6", ba, pf, answer) == 0 && !answer); //tc
    assert(evaluate("!6|6&6|6", ba, pf, answer) == 0); //tc
    assert(evaluate("!(6|6)&6|6", ba, pf, answer) == 0); //tc
    assert(evaluate("(!6|6)&6|6", ba, pf, answer) == 0 && answer); //tc
    assert(evaluate(" ! ! 6 & ! ! 7 ", ba, pf, answer) == 0 && !answer); //tc
    assert(evaluate("!!", ba, pf, answer) == 1);
    assert(evaluate("!(!)", ba, pf, answer) == 1);
    assert(evaluate("(!!)", ba, pf, answer) == 1);
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

//MAKE SURE TO ESP TEST THE EXCLAMATION POINT
//SINCE THAT IS A UNARY OPERATOR IT MUST BE HANDLED CAREFULLY!!!
//ALSO THERE ARE STILL (ATLEAST ONE) COUT STATEMENT IN THE EVAL FUNC -- REMOVE THIS BEFORE SUBMITTING!!!