#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

random_device rd;
mt19937 e(rd());
uniform_real_distribution<double> dist(-10.0, 10.0);

int findIndexOfMaximum(vector<int> &vec){
    int low = 0;
    int high = vec.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        // cout << "low: " << low << "|" << "high: " << high << "|" << "mid: " << mid << endl; 
        if(vec[mid] > vec[mid+1] && vec[mid] > vec[mid-1])
            return mid;
        else{
            if(vec[mid] < vec[mid+1])
                low = mid + 1;
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int biconicSearch(vector<int> &vec, int key){
    int indexOfMax = findIndexOfMaximum(vec);
    // cout << indexOfMax << endl;
    int low1 = 0;
    int high1 = indexOfMax;
    int low2 = indexOfMax + 1;
    int high2 = vec.size() - 1;
    while(low1 <= high1){
        int mid = low1 + (high1 - low1) / 2;
        if (vec[mid] == key)
            return mid;
        else if(vec[mid] < key)
            low1 = mid + 1;
        else
            high1 = mid - 1;
    }
    while(low2 < high2){
        int mid = low2 + (high2 - low2) / 2;
        if (vec[mid] == key)
            return mid;
        else if(vec[mid] < key)
            high2 = mid - 1;
        else
            low2 = mid + 1;
    }
    return -1;

}



int main(){
    cout << nounitbuf;
    vector<int> ivec = {1,2,3,4,5,-2,-3};
    vector<int> array1 = {1, 2, 3, 4, -1, -2, -3};
    vector<int> array2 = {1, 5, 4, 3, 2, 0};
    vector<int> array3 = {2, 4, 8, 16, 32, 1};
    cout << biconicSearch(ivec, -2) << endl;
    cout << biconicSearch(array1, -1) << endl;
    cout << biconicSearch(array2, 5) << endl;
    cout << biconicSearch(array3, 2) << endl;
    cout << biconicSearch(array3, 99) << endl;
    return 0;
}