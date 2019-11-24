#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

random_device rd;
mt19937 engine(rd());
uniform_int_distribution<int> dist(INT16_MIN, INT16_MAX);


void printCommonNumbers(vector<int> &a, vector<int> &b){
    auto asize = a.size();
    auto bsize = b.size();

    for(size_t i = 0, j = 0; i < asize && j < bsize; ){
        if(a[i] == b[j]){
            // cout << a[i] << " ";
            i++;
            j++;
        }else if (a[i] < b[j]){
            i++;
        }else{
            j++;
        }
    }
  
}


int main(){
    cout << nounitbuf;
    vector<int> a,b;
    for(size_t i = 250; true; i += i){
        for(int j = 0; j < i; j++){
            a.push_back(dist(engine));
            b.push_back(dist(engine));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());


        auto start_time = chrono::high_resolution_clock::now();
        printCommonNumbers(a,b);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
        cout << "i: " << i << ", duration: " << duration.count() << endl;

    }
    return 0;
}