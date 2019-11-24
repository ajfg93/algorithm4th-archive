#pragma once
#include <stdexcept>
#include <iostream>
template <typename T>
class MaxPQ{
    public:
        MaxPQ(size_t maxN){
            std::cout << "heh" << std::endl;
            pq = new T[maxN + 1];
            N = 0;
            capacity = maxN;
        }

        MaxPQ(T arr[], size_t s) : MaxPQ(s){
            for(size_t t = 0; t < s; t++){
                insert(arr[t]);
            }
        }

        bool isEmpty(){
            return N == 0;
        }

        size_t size(){
            return N;
        }

        bool isFull(){
            return N == capacity;
        }

        void insert(T elem){
            if(isFull()){
                throw std::runtime_error("MaxPQ is full, can't insert.");
            }
            pq[++N] = elem;
            swim(N);
        }

        T delMax(){
            T max = pq[1];
            exch(1, N--);
            pq[N+1] = 4396;
            sink(1);
            return max;
        }

        MaxPQ(const MaxPQ&) = delete;
        MaxPQ& operator=(const MaxPQ&) const = delete;

        ~MaxPQ(){
            delete[] pq;
        }
    private:
        T* pq;
        size_t N, capacity;

        void exch(int i, int j){
            T temp = pq[i];
            pq[i] = pq[j];
            pq[j] = temp;
            
        }

        void swim(int k){
            while(k > 1 && pq[k/2] < pq[k]){
                exch(k/2, k);
                k = k / 2;
            }
        }

        void sink(int k){
            while(2*k <= N){
                int j = 2*k;
                if(j < N && pq[j] < pq[j+1])
                    j++;
                if(!(pq[k] < pq[j])){
                    break;
                }else{
                    exch(k, j);
                }
                k = j;
            }
        }
};