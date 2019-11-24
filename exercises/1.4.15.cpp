#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

size_t TwoSumFast(vector<int>& ivec){
    sort(ivec.begin(), ivec.end());
    decltype(ivec.size()) head = 0;
    auto tail = ivec.size() - 1;
    size_t cnt = 0;
    while(head < tail){
        if(ivec[head] == - ivec[tail]){
            //假设所有整数都不相同
            head++, tail--;
            cnt++;
        }else if(ivec[head] > - ivec[tail]){
            tail--;
        }else{
            head++;
        }
    }
    return cnt;
}


size_t ThreeSumFast(vector<int>& ivec){
    sort(ivec.begin(), ivec.end());
    // decltype(ivec.size()) head = 0;
    // auto tail = ivec.size() - 1;
    for(auto &s : ivec){
        cout << s << " ";
    }
    cout << endl;
    size_t cnt = 0;
    for(int i = 0; i < ivec.size(); i++){
        int head = i + 1;
        int tail = ivec.size() - 1;
        while(head < tail){
            if(ivec[i] + ivec[head] == - ivec[tail]){
                //假设所有整数都不相同
                cout << ivec[i] << "," << ivec[head] << "," << ivec[tail] << endl;
                head++, tail--;
                cnt++;
            }else if(ivec[i] + ivec[head] > - ivec[tail]){
                tail--;
            }else{
                head++;
            }
        }
    }

    return cnt;
}

int main(){
    cout << nounitbuf;
    vector<int> ivec = {-1,0,1,2,3,4,5,-2,122,-23,40,-40};
    cout << TwoSumFast(ivec) << endl;
    cout << ThreeSumFast(ivec) << endl;

    return 0;
}