/*
    计算括号是否匹配
    不匹配：[][, ([})
    匹配：([{}])
*/

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>
#include "resizing_array_stack.h"
using namespace ythlearn;
using namespace std;

int main(){
    Stack<char> p;
    char c;
    vector<char> cvec;
    while(1){
        cout << "Input a sequence: " << endl;
        string s;
        std::getline(cin, s);
        istringstream is(s);
        while(is >> c){
            if(c == '[' || c == '(' || c == '{' || c == ']' || c == ')' || c == '}')
                cvec.push_back(c);
        }
        cout << "Finishing collecting data" << endl;
        cout << "Sequence is:" << endl;
        for(const auto& ca: cvec){
            cout << ca;
        }
        cout << endl;
        bool flag = true;

        if(cvec.size() % 2 == 0){
            for(const auto &ca : cvec){
                if(ca == '[' || ca == '(' || ca == '{'){
                    p.push(ca);
                }else if(ca == ']' || ca == ')' || ca == '}'){
                    if(p.empty()){
                        flag = false;
                        break;
                    }else{
                        char p_re = p.pop();
                        if((p_re == '[' && ca == ']') || (p_re == '{' && ca == '}') || 
                        (p_re == '(' && ca == ')'));
                        else{
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }else{
            flag = false;
        }

        if (flag)
            cout << "True" << endl;
        else{
            cout << "False" << endl;
        }
        
        while(!p.empty()){
            p.pop();
        }
        cvec.clear();
    }

    return 0;
}