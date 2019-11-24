#pragma once
#include <algorithm>
#include <vector>
class MergeBottomUp{
    public:
        static void sort(std::vector<int> &a, std::vector<int> &aux, unsigned &count){
            int length = a.size();
            for(int sz = 1; sz < length; sz = sz + sz){
                for(int lo = 0; lo < length - sz; lo += sz + sz){
                    merge(a, aux, lo, lo + sz - 1, std::min(lo+sz+sz-1, length-1), count);
                }
            }
        }
    private:
        static void merge(std::vector<int> &a, std::vector<int> &aux, int lo, int mid, int hi, unsigned &count){
            if(a[mid] < a[mid+1])
                return;

            for(int k = lo; k <= hi; k++){
                aux[k] = a[k];
                count += 2;
            }

            int i = lo, j = mid+1;

            for(int k = lo; k <= hi; k++){
                if(i > mid){
                   a[k] = aux[j++]; 
                }else if (j > hi){
                    a[k] = aux[i++];
                }else if(aux[i] < aux[j]){
                    a[k] = aux[i++];
                    count += 2;
                }else{
                    a[k] = aux[j++];
                    count += 2;
                }
                count += 2;
            }
        }
};