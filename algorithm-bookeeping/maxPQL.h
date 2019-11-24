#pragma once
#include <stdexcept>
template <typename T>
class MaxPQL{
    public:
        class Node{
            public:
                T item;
                Node* parent;
                Node* leftChild;
                Node* rightChild;
        };

        MaxPQL(){
            root = new Node;
            root->parent = root->leftChild = root->rightChild = nullptr;
            root->elem = 4396;
            insertPlaceNode = lastNode = root;
            N = 0;
        }

        bool isEmpty(){
            return N == 0;
        }

        size_t size(){
            return N;
        }

        void insert(T elem){
            Node* n = new Node;
            n->item = elem;
            n->leftChild = n->rightChild = nullptr;
            n->parent = insertPlaceNode;
            if(insertPlaceNode->left == nullptr){
                insertPlaceNode->left = n;
                lastNode = n;
                //insertPlaceNode is still this Node itself.
            }else if(insertPlaceNode->right == nullptr){
                insertPlaceNode->right = n;
                lastNode = n;
                insertPlaceNode = insertPlaceNode->left;
            }
            swim(n);
        }

        T delMax(){
            T max = pq[1];
            exch(1, N--);
            pq[N+1] = 4396;
            sink(1);
            return max;
        }

        MaxPQL(const MaxPQL&) = delete;
        MaxPQL& operator=(const MaxPQL&) const = delete;

        ~MaxPQL(){
            delete[] pq;
        }
    private:
        Node* root, *lastNode, *insertPlaceNode;
        size_t N;

        void exch(Node* i, Node* j){
            T temp = i->item;
            i->item = j->item;
            j->item = temp;
        }

        void swim(Node* k){
            while(k != root && k->parent->item < k->item){
                exch(k->parent, k);
                k = k->parent;
            }
        }

        void sink(Node* k){
            
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