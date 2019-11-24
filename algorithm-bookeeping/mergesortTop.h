#pragma once
#include <vector>
#include <iostream>

class InsertionSort{
    public:
        static void sort(std::vector<int> &a, int lo, int hi){
            for(int i = lo + 1; i <= hi; i++){
                int temp = a[i];
                int j = i;
                for(; j > lo && temp < a[j-1]; j--){
                    a[j] = a[j-1];
                }
                a[j] = temp;
            }
        }
};

template<typename T>
class MergeTopDown{
    public:
        static void sort(std::vector<T> &a, std::vector<T> &aux, unsigned &count){
            count = 0;
            sort(a, aux, 0, a.size() - 1, count);
        }
    private:    
        static const int cutoff = 7;
        static void sort(std::vector<T> &a, std::vector<T> &aux, int lo, int hi, unsigned &count){
            // if(hi - lo <= cutoff){
            //     InsertionSort::sort(a, lo, hi);
            //     return;                
            // }
            int mid = lo + (hi - lo) / 2;
            if(hi <= lo) return;            
            sort(a, aux, lo, mid, count);
            sort(a, aux, mid+1, hi, count);
            merge(a, aux, lo, mid, hi, count);
        }
        static void merge(std::vector<T> &a, std::vector<T> &aux, int lo, int mid, int hi, unsigned &count){
            // if(a[mid] < a[mid+1])
            //     return;

            for(int k = lo; k <= hi; k++){
                aux[k] = a[k];
            }

            int i = lo, j = mid+1;

            for(int k = lo; k <= hi; k++){
                if(i > mid){
                   a[k] = aux[j++]; 
                }else if (j > hi){
                    a[k] = aux[i++];
                    count++;
                }else if(aux[i] < aux[j]){
                    a[k] = aux[i++];
                }else{
                    a[k] = aux[j++];
                    count++;
                }
            }
        }
};