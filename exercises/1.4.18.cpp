#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

random_device rd;
mt19937 e(rd());
uniform_real_distribution<double> dist(-10.0, 10.0);

int findLocalMinima(vector<int> &vec){
    int left = 0;
    int right = vec.size() - 1;
    int middle = left + (right - left) / 2;

    while(middle != 0 && middle != vec.size() - 1){ 
        //如果写成while(left <= right)没有这样写好
        // cout << middle << " ";
        if(vec[middle] < vec[middle-1] && vec[middle] < vec[middle+1]){
            return middle;
        }else{
            if(vec[middle-1] < vec[middle]){
                //left  <----
                right = middle - 1;
            }else if(vec[middle+1] < vec[middle]){
                //----> right 
                left = middle + 1; 
            }else{
                throw runtime_error("error1");
            }
        }
        middle = left + (right - left) / 2;
    }
    return middle;
}


int main(){
    cout << nounitbuf;
    vector<int> vec = {6,5,4,3,2};
    vector<int> array1 = {10, -9, 20, 25, 21, 40, 50, -20};
    vector<int> array2 = {-4, -3, 9, 4, 10, 2, 20};
    vector<int> array3 = {5, -3, -5, -6, -7, -8};
    vector<int> array4 = {5};
    vector<int> array5 = {10, 20};
    vector<int> array6 = {7, 20, 30};
    cout << findLocalMinima(vec) << endl;
    cout << findLocalMinima(array1) << endl;
    cout << findLocalMinima(array2) << endl;
    cout << findLocalMinima(array3) << endl;
    cout << findLocalMinima(array4) << endl;
    cout << findLocalMinima(array5) << endl;
    cout << findLocalMinima(array6) << endl;
    return 0;
}