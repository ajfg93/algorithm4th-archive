/*

    中缀表达式，转后缀表达式

*/


#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>
#include "stack_linked_list.h"
using namespace ythlearn;
using namespace std;



int main(){
    Stack<string> ops, vals;
    cout << "Input a sequence: " << endl;
    string ss = "";
    std::getline(cin, ss);
    istringstream is(ss);
    string s;
    while(is >> s){
        if(s == "(");
        else if(s == "+" || s == "-" || s == "*" || s == "/"){
            ops.push(s);
        }
        else if(s == ")"){
            string op = ops.pop();
            string val = vals.pop();
            string re = vals.pop() + " " + val + " " + op;
            vals.push(re);
        }else{
            vals.push(s);
        }   
    }
    
    cout << vals.pop() << endl;

    return 0;
}