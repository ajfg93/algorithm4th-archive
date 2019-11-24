#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>
#include "quickUnionWP.h"
#include "quickUnionWP2.h"

using namespace std;

random_device rd;
mt19937 e(rd());
uniform_real_distribution<double> dist(-10.0, 10.0);


int main(){
    cout << nounitbuf;
    // int p,q;
    // fstream fs("testuf.txt");
    fstream fs("result.txt");
    long sum = 0;
    int N = 10;
    for(int j = 10; j <= 1000; j++){
        
        for(int i = 0; i < N; i++){
            quickUnionWP2 uf(j);
            auto x = uf.count();
            cout << x << "|";
            sum += x;
        }
        // cout << endl;
        long avg = sum / N;
        cout << "j: " << j << ", avg: " << avg  << endl;
        fs << avg << '\n';
        sum = 0;

    }

    // while(fs >> p >> q){
    //     if(uf.connected(p, q))
    //         continue;
    //     else{
    //         uf.unionn(p, q);
    //         cout << p << " " << q << endl;
    //     }
    // }
    // cout << "==================" << endl;
    // uf.print();
    // cout << uf.components << " components" << endl;

    return 0;
}