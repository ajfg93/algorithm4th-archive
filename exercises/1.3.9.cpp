/*

    补全中缀表达式缺少的括号
    输入： 1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )
    输出： ( ( 1 + 2 ) * ( ( 3 - 4 ) * ( 5 - 6 ) ) )
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
             vals.push("( " + vals.pop() + " " + op + " " + val + " )");
        }else{
            vals.push(s);
        }   
    }
    cout << vals.pop() << endl;

    return 0;
}