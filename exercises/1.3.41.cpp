#include <iostream>
#include "queue_linked_list.h"
using namespace std;
using namespace ythlearn;

int main(){
    Queue<int> q;
    for(int i = 0; i < 100; i++){
        q.enqueue(i);
    }

    Queue<int>* nq = new Queue<int> (q);
    while(!nq->empty()){
        cout << nq->dequeue() << " ";
    }
    cout << endl;
    cout << q.size() << endl;
    delete nq;
    return 0;
}