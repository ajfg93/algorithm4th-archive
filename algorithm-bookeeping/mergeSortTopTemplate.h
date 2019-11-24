#pragma once
#include <vector>
#include <iostream>
#include "insertionSortTemplate.h"

class MergeTopDown{
    public:
        template <typename Y>
        static Queue<Y> sort(Queue<Y> &a, Queue<Y>&b, unsigned &count){
            //Only for Queue<T>
            count = 0;
            int size = a.size + b.size;
            Queue<Y> c(size);
            while(!a.empty()){
                c.enqueue(a.dequeue());
            }
            while(!b.empty()){
                c.enqueue(b.dequeue());
            }
            std::vector<Y> aux(size);
            sort(c, aux, size - 1, count);
            return c;
        }

        template <typename T, typename Q>
        static void sort(T &a, Q &aux, int size, unsigned &count){
            count = 0;
            sort(a, aux, 0, size, count);
        }
    private:    
        static const int cutoff = 7;
        
        template <typename T, typename Q>
        static void sort(T &a, Q &aux, int lo, int hi, unsigned &count){
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

        template <typename T, typename Q>
        static void merge(T &a, Q &aux, int lo, int mid, int hi, unsigned &count){
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
                }else if(aux[i] < aux[j]){   //只要实现了比较运算符 < 和 下标运算符 [] 就可以 用
                    a[k] = aux[i++];         //链表 下标 运算符， 每次获取都得遍历， 消耗挺高的
                    count += 2;
                }else{
                    a[k] = aux[j++];
                    count += 2;
                }
                count += 2;
            }
        }
};