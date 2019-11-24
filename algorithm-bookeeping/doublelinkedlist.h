#pragma once
#include <stdexcept>
#include <iostream>
#include <initializer_list>
namespace ythlearn{
    template<typename T>
    class DLinkList{
        public:
            class Node{
                public:
                    Node* next;
                    Node* prev;
                    T elem;
            };
            Node head;
            Node tail;
            int _size;
            bool linked;
        public:
            void catenation(DLinkList& rhs){
                tail.next->next = rhs.head.next;
                rhs.head.next->prev = tail.next;
                rhs.tail.next->next = head.next;
                head.next->prev = rhs.tail.next;
                tail.next = rhs.tail.next;
                rhs.linked = true;
                _size += rhs._size;
            }

            DLinkList(){
                head.next = head.prev = tail.next = tail.prev = nullptr;
                _size = 0;
                linked = false;
            }

            DLinkList(std::initializer_list<T> init_list){
                head.next = head.prev = tail.next = tail.prev = nullptr;
                _size = 0;
                linked = false;
                for(auto s = init_list.begin(); s!=init_list.end(); s++){
                    push_right(*s);
                }
            }

            int size(){
                return _size;
            }

            bool isEmpty(){
                return size() == 0;
            }

            T& operator[](int index){
                if(index >= size()){
                    throw std::runtime_error("Operator[] index overflow");
                }else{
                    int i = 0;
                    Node* n_ptr = head.next;
                    while(i != index){
                        n_ptr = n_ptr->next;
                        i++;
                    }
                    return n_ptr->elem;
                }
        
            }

            Node* getIndexPointer(int index){
                if(index >= size()){
                    throw std::runtime_error("getIndexPointer index overflow");
                }else{
                    int i = 0;
                    Node* n_ptr = head.next;
                    while(i != index){
                        n_ptr = n_ptr->next;
                        i++;
                    }
                    return n_ptr;
                }
            }

             Node* getIndexPointer(Node* start_position_ptr, int distance){
                if(distance >= size()){
                    throw std::runtime_error("getIndexPointer(with start_position) index overflow");
                }else{
                    int i = 0;
                    Node* n_ptr = start_position_ptr;
                    while(i != distance){
                        n_ptr = n_ptr->next;
                        i++;
                    }
                    return n_ptr;
                }
            }

            bool isSorted(){
                Node* n_ptr = head.next;
                while(n_ptr != tail.next->prev){
                    if(n_ptr->elem > n_ptr->next->elem)
                        return false;
                    n_ptr = n_ptr->next;
                }
                return true;
            }

            DLinkList& push_right(T elem){
                Node* n = new Node;
                n->elem = elem;
                if(isEmpty()){
                    head.next = tail.next = n;
                    n->next = n->prev = n;
                }else{
                    n->next = head.next;
                    n->prev = tail.next;
                    tail.next->next = n;
                    tail.next = n;
                    head.next->prev = tail.next;
                }
                ++_size;
                return *this;
            }

            DLinkList& push_left(T elem){
                Node* n = new Node;
                n->elem = elem;
                if(isEmpty()){
                    head.next = tail.next = n;
                    n->next = n->prev = n;
                }else{
                    n->next = head.next;
                    n->prev = tail.next;
                    tail.next->next = n;
                    head.next->prev = n;
                    head.next = n;
                }
                ++_size;
                return *this;
            }

            DLinkList& push_left_check_duplicated(T elem){
                Node* re_ptr = exists(elem);
                if(re_ptr){
                    delete_by_ptr(re_ptr);
                    push_left(elem);
                }else{
                    push_left(elem);
                    ++_size;
                }
                return *this;
            }

            T pop_left(){
                if(isEmpty()){
                    throw std::runtime_error("Empty, can't pop left.");
                }else{
                    Node* node_to_delete = head.next;
                    head.next = head.next->next;
                    tail.next->next = head.next;
                    head.next->prev = tail.next;
                    T re_elem = node_to_delete->elem;
                    delete node_to_delete;
                    --_size;
                    if(isEmpty()){
                        head.next = tail.next = nullptr;
                    }
                    return re_elem;
                }
            }   

            T pop_right(){
                if(isEmpty()){
                    throw std::runtime_error("Empty, can't pop right.");
                }else{
                    Node* node_to_delete = tail.next;
                    tail.next->prev->next = head.next;
                    head.next->prev = tail.next->prev;
                    tail.next = tail.next->prev;
                    T re_elem = node_to_delete->elem;
                    delete node_to_delete;
                    --_size;
                    if(isEmpty()){
                        head.next = tail.next = nullptr;
                    }
                    return re_elem;
                }
            }

            T delete_by_ptr(Node * n_ptr){
                if (n_ptr == head.next){
                    return pop_left();
                }else if (n_ptr == tail.next){
                    return pop_right();
                }else{
                    n_ptr->prev->next = n_ptr->next;
                    n_ptr->next->prev = n_ptr->prev;
                    T re_elem = n_ptr->elem;
                    delete n_ptr;
                    --_size;
                    return re_elem;
                }
            }

            Node* exists(T elem){
                Node* loopPtr = head.next;
                do{
                    if(loopPtr->elem == elem){
                        return loopPtr;
                    }
                    loopPtr = loopPtr->next;
                }while(loopPtr != head.next);
                return nullptr;
            }

            void remove_duplicated_with_ordered(){
                //need ordered data
                //只在首次填充数据的时候使用
                Node* loopPtr = head.next;
                while(loopPtr != tail.next){
                    if(loopPtr->elem == loopPtr->next->elem){
                        Node* elem_to_delete = loopPtr;
                        loopPtr = loopPtr->next;
                        delete_by_ptr(elem_to_delete);
                    }else{
                        loopPtr = loopPtr->next;
                    }                    
                }
            }

            void print(){
                Node* loopPtr = head.next;
                if(!isEmpty()){
                    while(loopPtr != tail.next){
                        std::cout << loopPtr->elem << " ";
                        loopPtr = loopPtr->next;
                    }
                    std::cout << tail.next->elem << std::endl;
                }
            }

            void killOrder(int N, int M){
                for(int i = 0; i < N; i++){
                    push_right(i);
                }
                int j = 1;
                Node* loopPtr = head.next;
                while(!isEmpty()){
                    if(j == M){
                        Node* delete_ptr = loopPtr;
                        loopPtr = loopPtr->next;
                        std::cout << delete_by_ptr(delete_ptr) << " ";
                        j = 1;
                        continue;
                    }
                    loopPtr = loopPtr->next;
                    j++;
                }
                std::cout << std::endl;
            }



            DLinkList(const DLinkList&) = delete;
            DLinkList& operator=(const DLinkList&) const = delete;
            ~DLinkList(){
                std::cout << "Fuck" << std::endl;
                if(!linked){
                    Node* node_to_delete;
                    while(head.next != tail.next){
                        node_to_delete = head.next;
                        head.next = head.next->next;
                        delete node_to_delete;
                    }
                    // std::cout << "hi" << std::endl;
                    delete tail.next;
                }
            }

    };
}