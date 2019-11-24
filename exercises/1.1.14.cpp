/*
    计算不大于lg2(N)的正整数
    能用这种算法是因为y = 2^x的函数图像是连续且单调的
*/

#include <iostream>
using namespace std;

int lg2(int N){
    if(N <= 0){
        return -1;
    }
    else if (N == 1){
        return 0;
    }
    else{
        int n = 1;
        int cnt = 1;
        while((n = n*2) <= N){
            cnt++;
        }
        return cnt - 1;
    }

}

int main(){
    
    int inPut = 0;

    cout << "Input N:" << endl;
    while(cin >> inPut){
        cout << "===========" <<endl;
        cout << lg2(inPut) << endl;
        cout << "-----------" <<endl;
        cout << "Input N:" << endl;
    }

    cout << endl;
    return 0;
}
