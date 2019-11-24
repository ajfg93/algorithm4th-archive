#pragma once
#include "queue_resizing_array.h"

class InsertionSort{
    public:
        template <typename T>
        static void sort(T &a, int lo, int hi){
            for(int i = lo + 1; i <= hi; i++){
                int temp = a[i];
                int j = i;
                for(; j > lo && temp < a[j-1]; j--){
                    a[j] = a[j-1];  //只要实现了比较运算符 < 以及 下标运算符就可以用这个
                }
                a[j] = temp;
            }
        }
        
        //所有的Queue<Y> 都能用
        template<typename Y>  
        static Queue<Y> sortArrayQueue(Queue<Y> &a, Queue<Y> &b){
            Queue<Y> c(a.size + b.size);
            while(!a.empty()){
                c.enqueue(a.dequeue());
            }
            while(!b.empty()){
                c.enqueue(b.dequeue());                
            }
            sort(c, 0, c.size - 1);
            return c;
        }
};