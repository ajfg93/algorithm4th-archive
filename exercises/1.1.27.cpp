/*

    1. binomial_old_my是我增加了edge case的最原始的算法。
    2. binomial是标准答案
    3. binomial_my是增加了edge cases的标准答案

    递归算法，是从组合的递归推导出来的，即是：
    通过： C(n,k) = C(n-1, k-1) + C(n-1, k) ,对所有n >= 0 都成立
    推导出 b(n,k) = (1-p) * b(n-1, k-1) + p * b(n-1 ,k) ，对所有 n>=0 都成立
    
    优化后的算法，主要是将一些重复计算的递归存起来了，可以减少非常多的重复计算。
    可以画一个类似树的图， 可以发现重复计算很多。
    
    心得：
        1.通过 C(n, 0) = 1, C(n, n) = 0
          得到 b(n, 0) = (1-p)^n, b(n, n) = p^n
          增加这个两个edge case的确能减少一些运算，但在这里还是无法发生质变，
          无法引起数量级的变化。

        2.数组的初始化跟算法有关系。
          如果要用原来的条件，就必须将二维数组初始化为-1，这个时候会有b(n, k) = 0
          n < k的值。
          如果用我自己增加了edge cases的，就根本不会有值0存在。不会遍历到 
          n < k。

          测试数据： n = 100, k = 50, p = 0.5
                    =======1======= 标准答案
                    376250
                    0.025225
                    =======2======= 增加了edge cases的
                    250000
                    0.025225

                    也就剩了12万次计算，没有数量级上的变化。
    
    其他：
        不知道为什么，n = 4000, k = 2000的时候
*/



#include <iostream>
#include <cmath>
using namespace std;

long int cnt = 0;
long int cnt2 = 0;

//标准答案
template <size_t t1, size_t t2>
double binomial(double (&arr)[t1][t2], int N, int k, double p){
    if(N == 0 && k ==0) return 1.0;
    if (N<0 || k <0) return 0.0;
    if(arr[N][k] == -1){
        cnt++;
        arr[N][k] = (1.0 - p) * binomial(arr, N-1, k, p) + p*binomial(arr, N-1, k-1, p);
    }
    return arr[N][k];
}

template<size_t t1, size_t t2>
double binomial_my(double (&arr)[t1][t2], int N, int k, double p){
    if (N == k) return 1.0 * std::pow(p, N);
    if(k==0) return 1.0 * std::pow(1-p, N);
    if (N<0 || k <0 || N < k) return 0.0;
    if(!arr[N][k]){
        cnt2++;
        arr[N][k] = (1.0 - p) * binomial_my(arr, N-1, k, p) + p*binomial_my(arr, N-1, k-1, p);
    }
    return arr[N][k];
}

//我的，原始的算法
double binomial_old_my(int N, int k, double p){
    if (N == k) return 1.0 * std::pow(p, N);
    if(k==0) return 1.0 * std::pow(1-p, N);
    if (N<0 || k <0 || N < k) return 0.0;
    return (1.0 - p) * binomial_old_my(N-1, k, p) + p * binomial_old_my(N-1, k-1, p);
}

int main(){
    double p;
    const int N = 1000;
    const int k = 500;
    double M[N+1][k+1] = {0};
    p = 0.50;

    for(int i = 0; i < N+1; i++){
        for(int j = 0; j<k+1; j++){
            M[i][j] = -1;
        }
    }

    double Q[N+1][k+1] = {0};

    double re = binomial(M, N, k, p);
    double re2 = binomial_my(Q, N, k, p);
    cout << "=======1=======" <<endl;
    cout << cnt << endl << re <<endl;
    cout << "=======2=======" <<endl;
    cout << cnt2 << endl << re2 <<endl;

    return 0;
}
