#include <iostream>
#include "stack_linked_list.h"
using namespace std;
using namespace ythlearn;

int main(){
    Stack<int> q;
    for(int i = 0; i < 100; i++){
        q.push(i);
    }

    Stack<int>* nq = new Stack<int> (q);
    while(!nq->empty()){
        cout << nq->pop() << " ";
    }
    cout << endl;
    cout << q.size() << endl;
    delete nq;
    return 0;
}