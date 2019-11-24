/*
    投掷一个骰子是均匀分布，但投掷两个骰子的和，
    就不是均匀分布了。
    
    所以模拟投掷的时候，随机数生成必须要用均匀分布，
    如果用二项分布这种，结果应该就不对了。
*/


#include <iostream>
#include <random>
#include <iomanip>
using namespace std;


int main(){

    cout << left;
    const int SIDES = 6;
    double *dist = new double[2*SIDES+1];
    for(int i = 1; i <= SIDES; i++){
        for(int j = 1; j <= SIDES; j++)
            dist[i+j] += 1.0;
    }

    for(int k = 2; k <=2*SIDES; k++){
        dist[k] /= 36.0;
    }

    for(int k = 2; k <=2*SIDES; k++){
        cout << setw(10) << k << " ";
    }
    cout <<endl;

    for(int k = 2; k <=2*SIDES; k++){
        cout << setw(10) << dist[k] << " ";
    }
    cout << endl;
    
    cout << "============simulator==========" << endl;

    default_random_engine e;
    uniform_int_distribution<unsigned> u(1, 6);

    // const long int N = 15000000; 1500万次可以
    const long int N = 10000000;
    
    double simulator[2*SIDES+1] = {0};
    for(size_t i = 0; i < N; i++){  //唯一难点在这
        simulator[u(e) + u(e)]++;   //总共投掷N次，每次投资两枚骰子
    }

    for(int i = 2; i <= 2*SIDES; i++) {
        simulator[i] /= N;
    }

    for(int i = 2; i <= 2*SIDES; i++) {
        cout << setw(10) << simulator[i] << " ";
    }

    cout << endl;


    delete[] dist;
    return 0;
}