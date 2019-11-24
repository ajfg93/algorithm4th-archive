#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <random>
#include "maxPQ.h"
using namespace std;
using namespace std::chrono;

random_device rd;
mt19937 e(rd());
uniform_int_distribution<int> dist(INT16_MIN, INT16_MAX);

int main(){
    // int N = 10000;
    // for(int i = 0; i < 10; i++){
    //     unsigned j = 0;
    //     vector<int> l;
    //     for(int j = 0; j < N; j++){
    //         l.push_back(dist(e));
    //     }
    //     QuickSort<int>::sort(l, 0, l.size() - 1, j);
    //     cout << j << endl;
    // }
    int arr[] = {5,-3,2,10,0};
    MaxPQ<int> maxpq(arr, sizeof(arr) / sizeof(arr[0]));
    while(!maxpq.isEmpty()){
        cout << maxpq.delMax() << ",";
    }
    cout << endl;
    // maxpq.insert(12);
    return 0;
}