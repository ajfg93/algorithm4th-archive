#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

random_device rd;
mt19937 e(rd());
uniform_real_distribution<double> dist(-10.0, 10.0);

double FindClosestPair(vector<double>& vec){
    sort(vec.begin(), vec.end()); //NlogN
    for(auto& s: vec){
        cout << s << " ";
    }
    cout << endl;
    double min = abs(vec[0] - vec[1]);
    size_t index;
    for(size_t i = 1; i < vec.size() - 1; i++){
        double differ = abs(vec[i] - vec[i+1]);
        if(differ < min){
            min = differ;
            index = i;
        }
    }
    cout << "index:" << index << endl;
    return min;
}

double FindLargestPair(vector<double>& vec){
    //Find the largest number and the smallest number.
}

void GenerateRandom(vector<double> &vec, int N = 10){
    for(int i = 0; i < N; i++){
        vec.push_back(dist(e));
    }
}

int main(){
    cout << nounitbuf;
    vector<double> vec;
    GenerateRandom(vec);
    cout << FindClosestPair(vec) << endl;

    return 0;
}