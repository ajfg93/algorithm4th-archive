/*

    传参的时候用了depth++，结果递归里面depth一直都是1，
    因为depth+++返回的是depth+1之前的值

*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int binary_search(int key, int a[], int left_index, int right_index, int depth = 1){
    if(left_index > right_index)
        return -1;
    for(int i = 1;i < depth; i++)
        cout << '*';
    cout << left_index << ',' << right_index << endl;
    int mid = left_index + (right_index - left_index) / 2 ;
    if (key < a[mid])
        return binary_search(key, a, left_index, mid - 1, ++depth);
    else if(key > a[mid])
        return binary_search(key, a, mid + 1, right_index, ++depth);
    else
        return mid;
}

int main(){
    fstream fp("tinyW.txt");
    int a[15] = {};
    int i = 0;
    if(fp.is_open()){
       while(fp >> a[i])
           i++;
    }
    sort(begin(a), end(a));
    binary_search(23, a, 0, 14);
    return 0;
}
