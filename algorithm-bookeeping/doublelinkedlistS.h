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

        DLinkList(const DLinkList&) = delete;
        DLinkList& operator=(const DLinkList&) const = delete;
        ~DLinkList(){
            if(!linked){
                Node* node_to_delete;
                while(head.next != tail.next){
                    node_to_delete = head.next;
                    head.next = head.next->next;
                    delete node_to_delete;
                }
                delete tail.next;
            }
        }

    };
}