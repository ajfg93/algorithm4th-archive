#pragma once
#include <vector>
#include <iostream>

class MergeTopDown{
public:
    static void sort(std::vector<int> &a, std::vector<int> &aux){
        sort(a, aux, 0, a.size() - 1);
    }
private:
    static void sort(std::vector<int> &a, std::vector<int> &aux, int lo, int hi){
        int mid = lo + (hi - lo) / 2;
        if(hi <= lo) return;
        sort(a, aux, lo, mid);
        sort(a, aux, mid+1, hi);
        merge(a, aux, lo, mid, hi);
    }
    static void merge(std::vector<int> &a, std::vector<int> &aux, int lo, int mid, int hi){
        for(int k = lo; k <= hi; k++){
            aux[k] = a[k];
        }

        int i = lo, j = mid+1;

        for(int k = lo; k <= hi; k++){
            if(i > mid){
                a[k] = aux[j++];
            }else if (j > hi){
                a[k] = aux[i++];
            }else if(aux[i] < aux[j]){
                a[k] = aux[i++];
            }else{
                a[k] = aux[j++];
            }
        }
    }
};