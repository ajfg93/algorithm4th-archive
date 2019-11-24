#pragma once
#include <random>
#include <ctime>
#include <iostream>

namespace ythlearn{
    std::default_random_engine e(std::time(0));

    template <typename T>
    class RandomBag{
        public:
            RandomBag(int N = 15){
                head = new T[N];
                _capacity = 15;
                _size = 0;
                tail = head;
            }

            bool isEmpty(){
                return _size == 0;
            }            

            bool isFull(){
                return _size == _capacity;
            }

            int size(){
                return _size;
            }

            void add(T elem){
                if(isFull()){
                    resize();
                }
                *tail++ = elem;
                ++_size;
            }

            void resize(int x = 2){
                int newCapacity = _capacity * x;
                T* newHead = new T[newCapacity];
                T* newHeadCopy = newHead;
                T* oldHeadCopy = head;
                while(oldHeadCopy != tail){
                    *newHeadCopy++ = *oldHeadCopy++;
                }
                delete[] head;
                head = newHead;
                tail = newHeadCopy;
                _capacity = newCapacity;
            }

            void shuffle(){
                T* headCopy = head;
                int i = 0;
                while(headCopy != tail - 1){
                    std::uniform_int_distribution<int> u(0, size() - 1 - i);
                    int num = u(e);
                    std::swap(*headCopy, *(headCopy+num));
                    // std::cout << size() - 1 - i << "|";
                    headCopy++;
                    i++;
                }

            }

            T* begin(){
                shuffle();
                return head;
            }

            T* end(){
                return tail;
            }

            RandomBag& operator=(const RandomBag&) = delete;
            RandomBag(const RandomBag&) = delete;
            ~RandomBag(){
                delete[] head;
            }
        private:
            T *head;
            T *tail;
            int _size;
            int _capacity;
    };
    
}

