#pragma once
#include <vector>
#include <iostream>

template <typename T>
class QuickSort{
public:
    static void sort(std::vector<T> &vec, int lo, int hi, unsigned &cnt){

        if(hi <= lo)
            return;
        int j = partition(vec, lo, hi, cnt);

        sort(vec, lo, j-1, cnt);
        sort(vec, j+1, hi, cnt);
    }

private:
    static int partition(std::vector<T> &vec, int lo, int hi, unsigned &cnt){
        // std::cout << "(" << lo << "," << hi << ")" << std::endl;
        // for(int i = 0; i < vec.size(); i++) {
        //     std::cout << vec[i] << ",";
        // }
        // std::cout << std::endl;
        cnt += hi - lo + 1;

        int i = lo, j = hi + 1;
        T v = vec[lo];
        while(true){
            while(v > vec[++i]){
                if(i == hi)
                    break;
            }
            while(v < vec[--j]);
            if(i >= j)
                break;
            exch(vec, i, j);
        }
        exch(vec, lo, j);
        return j;
    }

    static void exch(std::vector<T> &vec, int a, int b){
        T temp = vec[a];
        vec[a] = vec[b];
        vec[b] = temp;
    }
};