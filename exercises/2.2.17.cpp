#include <iostream>
#include <random>
#include "singlelinkedlist.h"
#include <chrono>
#include <cassert>
using namespace std;
using namespace ythlearn;
using namespace std::chrono;

random_device rd;
mt19937 e(rd());
uniform_int_distribution<int> dist(INT16_MIN, INT16_MAX);

int main(){
    cout //<< "i\t"
            << "runtime\t" << endl;

    for(int i = 500; i <= 2097152; i += 2500){
        Linkedlist<int> l;
        for(int j = 0; j < i; j++){
            l.push_left(dist(e));
        }
        auto start = high_resolution_clock::now();
        l.call_merge();
        auto stop = high_resolution_clock::now();
        // assert(l.isSorted());
        auto duration = duration_cast<microseconds>(stop - start);
        cout <<  duration.count() << endl;
    }

    // Linkedlist<int> l = {1,2,3,4,5,6,7,8};
    // l.print();
    // l.call_merge();
    // l.print();
    // assert(l.isSorted());
    return 0;
}