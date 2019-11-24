#pragma once
#include <iostream>
#include <random>



class quickUnionWP2{
    public:
        class Node{
            public:
                Node(){
                    
                }
                Node(int i){
                    id = i;
                    has_count = false;
                }
                int id;
                bool has_count;
        };

        quickUnionWP2(int N){
            components = size = N;
            id = new Node[N];
            sz = new int[N];
            for(int i = 0; i < size; i++){
                id[i] = Node(i);
                sz[i] = 1;
                // std::cout << i << " ";
            }
            // std::cout << std::endl;
        }

        int find(int p){
            int p2 = p;
            while(p != id[p].id)
                p = id[p].id;
            int root = p;
            int nextP;
            while(p2 != root){
                nextP = id[p2].id;
                id[p2].id = root;
                p2 = nextP;
            }
            return root;
        }

        bool connected(int p, int q){
            return find(p) == find(q);
        }

        void unionn(int p, int q, bool doprint = true){
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot) return;
            if (doprint)
                print();
            if(sz[pRoot] < sz[qRoot]){
                id[pRoot].id = qRoot;
                sz[qRoot] += sz[pRoot];
            }else{
                //相等，右挂左
                id[qRoot].id = pRoot;
                sz[pRoot] += sz[qRoot];
            }
            if (doprint)
                print();
            components--;
        }

        void print(){
            for(int i = 0; i < size; i++){
                std::cout << id[i].id << " ";
            }
            std::cout << std::endl;
        }

        int count(){
            std::random_device rd;
            std::mt19937 e(rd());
            std::uniform_int_distribution<int> dist(0, size - 1);
            int p, q;
            int connectionsCnt = 0;
            while(components != 1){
                p = dist(e);
                q = dist(e);
                connectionsCnt++;
                if(connected(p, q))
                    continue;
                else{
                    unionn(p, q, false);
                    // std::cout << p << " " << q << std::endl;
                }
            }
            // std::cout << "------------------------" << std::endl;
            // print();
            // std::cout << components << " components" << std::endl;
            // int links = 0;
            // for(int i = 0; i < size; i++){
            //     int pp = i;
            //     while(pp != id[pp].id){
            //         if(!id[pp].has_count){
            //             id[pp].has_count = true;
            //             links++;
            //         }
            //         pp = id[pp].id;
            //     }
            // }
            return connectionsCnt;
        }

        ~quickUnionWP2(){
            delete[] id;
            delete[] sz;
        }

        int *sz;
        Node *id;
        int size, components;
    
};