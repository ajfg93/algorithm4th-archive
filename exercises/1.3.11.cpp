/*

    计算后缀表达式的值

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
    Stack<double> vals;
    cout << "Input a posfix notation expression: " << endl;
    string ss = "";
    std::getline(cin, ss);
    istringstream is(ss);
    string s;
    while(is >> s){
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            double val2 = vals.pop();
            double val1 = vals.pop();
            if(s == "+")
                vals.push(val1 + val2);
            else if (s == "-")
                vals.push(val1 - val2); // the order matters
            else if (s == "*")
                vals.push(val1 * val2);
            else
                vals.push(val1 / val2);
        }else{
            vals.push(std::stod(s));
        }
    }
    
    cout << vals.pop() << endl;

    return 0;
}