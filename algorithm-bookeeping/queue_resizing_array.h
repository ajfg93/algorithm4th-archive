#pragma once
#include <stdexcept>
#include <initializer_list>
template <typename T>
class Queue{
    public:
        Queue(std::initializer_list<T> init_list){
            int N = init_list.size();
            arr = new T[N];
            head = tail = arr;
            size = 0;
            capacity = N;
            onePastEndPtr = head + N;
            
            for(auto s = init_list.begin(); s!=init_list.end(); s++){
                enqueue(*s);
            }
        }

        Queue(int N = 10){
            arr = new T[N];
            head = tail = arr;
            size = 0;
            capacity = N;
            onePastEndPtr = head + N;
        }

        Queue& enqueue(T item){
            //push right
            if(full()){
                resize();
            }
            if(head < tail){
                *tail = item;
                if (tail + 1 == onePastEndPtr)
                    tail = arr;
                else
                    tail++;
            }else{
                *tail++ = item;
            }
            size++;
            
            return *this;
        }

        T dequeue(){
            //pop left
            if(empty()){
                throw std::runtime_error("Queue is empty, can't dequeue");
            }else{
                T elem = *head;
                if (head + 1 == onePastEndPtr)
                    head = arr;
                else
                    head++;
                size--;
                return elem;   
            }
        }

        void resize(){
            int N = capacity * 2;
            T* new_arr = new T[N];
            
            if(head < tail){
                for(int i = 0; i < size; i++){
                    new_arr[i] = arr[i];
                }
            }else{
                //head >= tail && isFull
                T* head_ptr = head;
                T* start_ptr = arr;
                while(head_ptr != onePastEndPtr){
                    *new_arr++ = *head_ptr++;
                }
                while(start_ptr != tail){
                    *new_arr++ = *start_ptr++;
                }
                
            }

            delete[] arr;
            arr = new_arr;
            head = arr;
            tail = head + size;
            onePastEndPtr = head + N;
            capacity = N;
        }

        bool empty(){
            return size == 0;
        }

        bool full(){
            return size + 1 == capacity;
        }


        ~Queue(){
            delete[] arr;
        }

        Queue(const Queue& rhs){
            arr = rhs.arr;
            head = rhs.head;
            tail = rhs.tail;
            size = rhs.size;
            capacity = rhs.capacity;
            onePastEndPtr = rhs.onePastEndPtr;
        }

        Queue& operator=(const Queue&) = delete;

        T& operator[](size_t index){
            return arr[index];
        }

        T* arr;
        T* head, *tail;
        int size, capacity;
        T* onePastEndPtr;
};