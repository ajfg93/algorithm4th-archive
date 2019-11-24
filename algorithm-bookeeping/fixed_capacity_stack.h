/*

    Fixed Capacity Stack, 
    with a usage of Dijkstra’s two-stack arithmetic expression-evaluation algorithm

*/

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cmath>

namespace ythlearn{
template<typename T>
    class Stack{
        public:
            Stack(int N):capacity(N),pos(0){
                a = new T[N];   //索引只到N-1，N就是Stack的size
            }

            void push(T item){
                if(pos + 1 > capacity){   //pos可以越界（尾后指针），即可以存满, 允许 pos+1 == capacity
                    std::cerr << "Error: Stack is full." << std::endl;
                }else{
                    a[pos++] = item;
                }
            }

            T pop(){
                if(empty()){
                    std::cerr << "Error: Stack is empty, can't pop." << std::endl;
                    throw std::runtime_error("Stack Pop error");
                }else{
                    return a[--pos];
                }
            }

            T top(){
                if(empty()){
                    std::cerr << "Stack is empty, can't top." << std::endl;
                }else{
                    return a[pos-1];
                }
            }

            int size(){
                return pos+1;
            }

            bool empty(){
                return pos == 0;
            }

            ~Stack(){
                delete[] a;
            }

            Stack(const Stack&) = delete;
            Stack& operator=(const Stack&) = delete;

        private:
        int capacity;  //N
        int pos;       //max(pos) = N-1 
        T *a;
    };
}
