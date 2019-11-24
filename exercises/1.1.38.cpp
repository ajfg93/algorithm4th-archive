/*

    测试数据, largeW.txt, 1亿条整型数据
    binary_search: 28ms
    brute_forech_search: 7085ms


*/


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;

long int binary_search(int key, vector<long int> &vec, long int lo, long int hi){
    if(lo > hi) 
        return -1;
    long int mid = lo + (hi - lo) / 2 ;
    if (key < vec[mid])
        return binary_search(key, vec, lo, mid - 1);
    else if(key > vec[mid])
        return binary_search(key, vec, mid + 1, hi);
    else 
        return mid;
}

size_t brute_force_search(int key, vector<long int> &vec){
    size_t i = 0;
    for(; i < vec.size(); i++){
        if (vec[i] == key)
            break;
    }
    if (i <= vec.size())
        return i;
    else 
        return -1;
}

int main(){
    vector<long int> ivec;
    // fstream fs("largeW.txt");
    fstream fs("largeT.txt");
    long int input = 0;
    while(fs >> input){
        ivec.push_back(input);
    }
    sort(ivec.begin(), ivec.end());
    long int key = 200067;

    auto start = std::chrono::high_resolution_clock::now();

    // long int binary_index = binary_search(key, ivec, 0, ivec.size());
    // cout << "=========binary_search=========" <<endl;
    // cout << binary_index << endl;
    // cout << ivec[binary_index] << endl;

    long int brute_index = brute_force_search(key, ivec);
    cout << "=========brute_force_search=========" << endl;
    cout << brute_index << endl;
    cout << ivec[brute_index] << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    return 0;
}