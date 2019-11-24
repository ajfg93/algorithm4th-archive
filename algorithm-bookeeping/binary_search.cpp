/*
Source: Algorithm 4th, Book

Introduction: Binary Search, use with sorted data.

Related reading:

*/
#include <iostream>
#include "binary_search.h"
using namespace std;

namespace ythlearn{
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
}

