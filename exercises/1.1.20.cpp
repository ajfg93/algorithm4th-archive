/*

    计算ln(N!)的结果, N!是N的阶乘
    
    这里有个很关键地方：
        这里必须用ln(AxB) = lnA + lnB 的性质来进行递归计算，
        不能先算N!，因为10!就已经是300万了。。
        如果先计算N!的值，那能计算的范围非常有限。

*/

#include <iostream>
#include <cmath>
using namespace std;

double lgN(int n){
    if (n == 1) return 0;
    return lgN(n-1) + std::log(n);
}


long long int factorial(long long int n){
    if (n == 1) return 1;
    return factorial(n-1) * n;
}

int main(){
    cout << lgN(500) << endl;
    long long int re = factorial(10);  //factorial(500)根本没办法算
    cout << re << endl;
    return 0;
}
