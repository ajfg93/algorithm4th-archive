/*
    ResizingArrayStack, a dynamically allocated size stack, 
    with a usage of Dijkstra’s two-stack arithmetic expression-evaluation algorithm

    support for(auto s: stack) loop statement
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
            Stack(int N = 1):capacity(N),pos(0){
                a = new T[N];   //索引只到N-1，N就是Stack的size
            }

            void push(T item){
                if(pos + 1 > capacity){   //pos可以越界（尾后指针），即可以存满, 允许 pos+1 == capacity
                    std::cout << "Log: Stack is full. Ready to enlarge." << std::endl;
                    resize(2 * capacity);
                }
                a[pos++] = item;

            }

            T pop(){
                if(empty()){
                    std::cerr << "Error: Stack is empty, can't pop." << std::endl;
                    throw std::runtime_error("Stack Pop error");
                }else{
                    if(pos >0 && (pos + 1) == capacity / 4){
                        std::cout << "Log; Stack is too large. Ready to shrink." << std::endl;
                        resize(capacity / 2);
                    }
                    return a[--pos];
                }
            }

            T top(){
                if(empty()){
                    std::cerr << "Stack is empty, can't top." << std::endl;
                    return -1;
                }else{
                    return a[pos-1];
                }
            }

            void resize(int newSize){
                T * b = new T[newSize];
                for(int i = 0 ; i < pos; i++){ //条件不设置为N是因为，会有缩小数组
                    b[i] = a[i];               //大小的情况，这个时候就不是全部copy了，只copy到pos-1
                }
                delete[] a;
                a = b;
                capacity = newSize;
            }

            int size(){
                return pos+1;
            }

            bool empty(){
                return pos == 0;
            }

            //迭代的支持
            T* begin(){
                return a;
            }

            T* end(){
                return a + pos;
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

