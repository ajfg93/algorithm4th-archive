/*
    0-9按顺序入栈，出入栈操作混合，问有哪些序列不可能
    主要算法在嵌套if里，其他的东西都是为了提供多次输入验证的功能。
*/
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cmath>
#include <vector>
#include "resizing_array_stack.h"
using namespace ythlearn;
using namespace std;

int main(){
    Stack<int> s;
    int input;

    s.push(0);
    int largest = 0;

    const int N = 10;
    int i = 1;

    while(cin >> input){  //一次输入10个
        if(input > largest){
            for(int i = largest + 1; i <= input; i++){
                s.push(i);
            }
            largest = s.pop();
            cout << largest;
        }else if(input == s.top()){
            cout << s.pop();
        }else{
            cout << endl;
            cout << "This sequence is wrong" << endl;
            cout << "clearing existing data, input a new sequence" << endl;
            while(!s.empty()){
                s.pop();
            }
            cin.ignore(1000, '\n');
            s.push(0);
            largest = 0;
            i = 1;
            continue;   //一个出口
        }

        if(i == N){
            cout << endl;
            cout << "This sequence is available" <<endl;
            s.push(0);   //另外一个出口
            largest = 0;
            i = 1;
        }else{
            i++;
        }

    }

    return 0;
}