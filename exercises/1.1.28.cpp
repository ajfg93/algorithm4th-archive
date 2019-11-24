/*
    这题其实跟BinarySearch好像没啥关系。。。
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    const int N = 18;
    int a[N] = {23,50,10,99,18,23,98,84,11,10,48,77,13,54,98,77,77,68};
    sort(begin(a), end(a));
    for(auto s : a){
        cout << s << ",";
    }
    cout << endl;

    for(int i = 0; i < N;){
        int j = i + 1;
        while(a[i] == a[j]){
            a[j] = -1;
            j++;
        }
        i = j;
    }
    for(auto s : a){
        cout << s << ",";
    }
    cout << endl;
    return 0;
}
