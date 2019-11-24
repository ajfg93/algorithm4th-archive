/*

    Fixed Capacity Stack, 
    with a usage of Dijkstra’s two-stack arithmetic expression-evaluation algorithm

*/

#include "fixed_capacity_stack.h"

//Test Case
/*
int main(){
 
    Stack<string> ops(100);
    Stack<double> vals(100);
    istringstream iss("( 1 + ( ( 2 + 3 ) * ( sqrt ( 4 ) ) )");
    string s;
    while(iss >> s){
        if (s == "(");
        else if(s == "+" || s == "-" || s == "*" || s == "/" || s == "sqrt")
            ops.push(s);
        else if(s == ")"){
            string op = ops.pop();
            double val = vals.pop();
            double re = 0;
            if (op == "+")
                re = val + vals.pop();
            else if (op == "-")
                re = val - vals.pop();
            else if (op == "*")
                re = val * vals.pop();
            else if (op == "/")
                re = val / vals.pop();
            else if (op == "sqrt")
                re = std::sqrt(val);
            vals.push(re);
        }else{
            vals.push(std::stod(s));
        }
    }
    cout << "expression reuslt:"
        << vals.pop() <<endl;
    return 0;
}
*/