/*

    这里要的不是一个真正意义上的队列Queue

*/

#pragma once
#include <random>
#include <utility>
#include <algorithm>
#include <iostream>
namespace ythlearn{
    std::random_device rd;
    std::mt19937 e(rd());
    template<typename T>
    class RandomQueue{
        public:
            RandomQueue(int N = 10){
                head = new T[N];
                _size = 0;
                _capacity = N;
            }

            bool isEmpty(){
                return size() == 0;
            }

            bool isFull(){
                return size() == _capacity;
            }

            int size(){
               return _size;
            }

            void enqueue(T item){
                if(isFull()){
                    resize();
                }
                head[size()] = item;
                _size++;
            }

            T dequeue(){
                //看原来的题目，这种方法也是可以的
                if(isEmpty()){
                    throw std::runtime_error("Queue empty, can't dequeue.");
                }else{
                    shuffle_once();
                    return head[--_size];
                }
            }

            T sample(){
                //看原来的题目，这种方法也是可以的
                if(isEmpty()){
                    throw std::runtime_error("Queue empty, can't dequeue.");
                }else{
                    shuffle_once();                    
                    return head[size() - 1];
                }
            }

            void shuffle_once(){
                if(size() > 1){
                    std::uniform_int_distribution<int> dist(0, size() - 2);
                    int index = dist(e);
                    std::swap(head[index], head[size() - 1]); 
                }
            }

            void shuffle_all(){
                if(size() > 1){
                    T* headCopy = head;
                    while(headCopy != (head + size())){
                        //原来这里是错的，经过了修改
                        //每一个元素都应该能跟包括他自己以内的所有元素交换
                        std::uniform_int_distribution<int> dist(0, size() - 1);
                        int index = dist(e);
                        std::swap(*headCopy, *(head + index));
                        headCopy++;
                    }
                    // std::cout << "I:" << i << std::endl;
                }
            }


            void resize(int multiplier = 2) {
                int newCapacity = _capacity * multiplier;
                T* newHead = new T[newCapacity];
                T* newHeadCopy = newHead;
                T* end_ptr = head + size();
                T* oldHeadCopy = head;
                while(oldHeadCopy != end_ptr){
                    *newHeadCopy++ = *oldHeadCopy++;
                }
                delete[] head;
                head = newHead;
                _capacity = newCapacity;
            }

            T* begin(){
                shuffle_all();
                return head;
            }

            T* end(){
                return head + size();
            }

            RandomQueue& operator=(const RandomQueue&) = delete;
            RandomQueue(const RandomQueue&) = delete;
            ~RandomQueue(){
                delete[] head;
            }
            
        public:
            T* head;
            int _size;   //用_size来标识：元素的个数，尾元素的位置，以及
            int _capacity;
    };
}