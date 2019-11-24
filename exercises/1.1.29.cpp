/*
    rank函数名跟std中有一个冲突，要改一下
    先用binary_search找到一个key的位置，
    因为是有序的，所以再从左右找就行了，
    没其他什么东西了

*/

#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int binary_search(int key, int a[], int lo, int hi){
    if(lo > hi)
        return -1;
    int mid = lo + (hi - lo) / 2 ;
    if (key < a[mid])
        return binary_search(key, a, lo, mid - 1);
    else if(key > a[mid])
        return binary_search(key, a, mid + 1, hi);
    else
        return mid;
}

template<size_t N>
int rankk(int key, int (&sorted_array)[N]){
    //sorted array中可以有重复的元素
    //返回所有小于key的元素的数量，即是最靠左的key的index + 1
    //同时a[index+1]为第一个等于key的元素
    //先用binary_search，找一个key的位置
    int first_shown_index = binary_search(key, sorted_array, 0, N);
    if (first_shown_index != -1){
        int i  = first_shown_index - 1;
        while((sorted_array[i] == key) && (i >= 0))
            i--;
        return i+1;
    }
    return -1;
}

template<size_t N>
int count(int key, int (&sorted_array)[N]){
    int first_shown_index = binary_search(key, sorted_array, 0, N);
    if (first_shown_index != -1){
        int cnt = 1;
        int l = first_shown_index - 1;
        int r = first_shown_index + 1;
        while((sorted_array[l] == key) && (l >= 0)){
            l--;
            cnt++;
        }
        while((sorted_array[r] == key) && (r < N)){
            r++;
            cnt++;
        }
        return cnt;
    }
    return -1;
}

int main(){
    const int N = 18;
    int a[N] = {23,50,10,99,18,23,98,84,11,10,48,77,13,54,98,77,77,68};
    sort(begin(a), end(a));
    for(auto s : a){
        cout << s << ",";
    }
    cout << endl;
    int b = rankk(77, a);
    int c = count(77, a);
    cout << b << endl << c << endl;
    return 0;
}
