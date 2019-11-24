/*
    数组的转置
    TODO: 怎么做成一个函数，传递一个二维数组，再返回一个其转置

*/

#include <iostream>
using namespace std;

int main(){

    int a[2][3] = {
            {1,2,3},
            {4,5,6}
    };

    int b[3][2] = {};

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            b[j][i] = a[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << '|' << b[i][j] << '|' ;
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}
