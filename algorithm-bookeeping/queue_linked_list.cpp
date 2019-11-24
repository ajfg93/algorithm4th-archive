/*

    A Queue based on linked-lists.
    With range-base for loop implemention.

    更新：
    1. 将头指针，改成头节点，头结点不是动态内存
    2. 添加了尾部节点，这样添加元素的时候就不用遍历了。。。

*/

#include <iostream>
#include "queue_linked_list.h"
using namespace std;

namespace ythlearn{
    template <typename T>
    void foo(Queue<T> &ls){
        cout << "==================" << endl;
        cout << boolalpha << ls.empty() <<endl;
        cout << ls.size() << endl;
        cout << "==================" << endl;
    }
}

//Test Case
/*
int main(){
    Queue<int> ls;
    ls.enqueue(1);
    ls.enqueue(2);
    ls.enqueue(3);
    for(auto s:ls){
        cout << s << ",";
    }
    cout << endl;
    cout << ls.dequeue() << endl;
    cout << ls.dequeue() << endl;
    foo(ls);
    cout << ls.dequeue() << endl;
    foo(ls);
    
    return 0;
}
*/