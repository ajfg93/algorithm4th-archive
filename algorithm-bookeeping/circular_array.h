#pragma once
#include <stdexcept>
#include <iostream>
namespace ythlearn{
    template<typename T>
    class CircularArray{
        public:
            CircularArray(int N = 1001){
                head = tail = new T[N];
                past_end_ptr1 = past_end_ptr2 = head + N;
                start_ptr1 = start_ptr2 = head;
                _capacity = N;
                _size = 0;
            }

            void push_right(T elem){
                *tail = elem;
                if(tail + 1 == past_end_ptr1){
                    tail = start_ptr1;
                }else{
                    tail++;
                }
            }

            bool tail_reach_end(){
                return tail + 1 == past_end_ptr1;
            }

            bool head_reach_end(){
                return head + 1 == past_end_ptr2;
            }

            bool head_reach_500_before_end(){
                return head + 1 == past_end_ptr2 - 500;
            }

            T pop_left(){
                T re = *head;
                if(head + 1 == past_end_ptr2){
                    head = start_ptr2;
                }else{
                    head++;
                }
                return re;
            }

            CircularArray& operator=(const CircularArray&) = delete;
            CircularArray(const CircularArray&) = delete;
            ~CircularArray(){
                delete[] start_ptr1;
            }
        
        T* past_end_ptr1, *past_end_ptr2;
        
        private:
            T* head;
            T* tail;
            T* start_ptr1, *start_ptr2;
            // T* past_end_ptr1, *past_end_ptr2;
            int _capacity;
            int _size;
    };
}