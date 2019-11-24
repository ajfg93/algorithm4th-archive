/*

    A Stack based on linked-lists.
    With range-base for loop implemention.

    更新：
    1. 将头指针，改成头节点，头结点不是动态内存

*/

#include <iostream>
#include "stack_linked_list.h"
using namespace std;

namespace ythlearn{
    template <typename T>
    void foo(Stack<T> &ls){
        cout << "==================" << endl;
        cout << boolalpha << ls.empty() <<endl;
        cout << ls.size() << endl;
        cout << "==================" << endl;
    }
}


//Test Case
/*
int main(){
    Stack<int> ls;
    ls.push(1);
    ls.push(2);
    ls.push(3);
    for(auto s:ls){
        cout << s << ",";
    }
    cout << endl;
    cout << ls.pop() << endl;
    cout << ls.pop() << endl;
    foo(ls);
    cout << ls.pop() << endl;
    foo(ls);
    
    return 0;
}
*/