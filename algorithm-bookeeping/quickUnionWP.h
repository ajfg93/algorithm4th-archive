#pragma once
#include <iostream>
#include <random>



class quickUnionWP{
    public:
        quickUnionWP(int N){
            components = size = N;
            id = new int[N];
            sz = new int[N];
            for(int i = 0; i < size; i++){
                id[i] = i;
                sz[i] = 1;
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }

        int find(int p){
            int p2 = p;
            while(p != id[p])
                p = id[p];
            int root = p;
            int nextP;
            while(p2 != root){
                nextP = id[p2];
                id[p2] = root;
                p2 = nextP;
            }
            return root;
        }

        bool connected(int p, int q){
            return find(p) == find(q);
        }

        void unionn(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) return;
            print();
            if(sz[pRoot] < sz[qRoot]){
                id[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }else{
                id[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
            print();
            components--;
        }

        void print(){
            for(int i = 0; i < size; i++){
                std::cout << id[i] << " ";
            }
            std::cout << std::endl;
        }

        ~quickUnionWP(){
            delete[] id;
            delete[] sz;
        }

        int *id, *sz;
        int size, components;
    
};