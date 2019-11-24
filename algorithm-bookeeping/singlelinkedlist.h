#pragma once
#include <stdexcept>
#include <iostream>
#include <initializer_list>
namespace ythlearn{
    template<typename T>
    class Linkedlist{
    public:
        class Node{
        public:
            Node* next;
            T elem;
        };
        Node head;
        int _size;
    public:
        Linkedlist(){
            head.next = nullptr;            
            _size = 0;
        }

        Linkedlist(std::initializer_list<T> init_list){
            head.next = nullptr;            
            _size = 0;
            for(auto s = init_list.begin(); s!=init_list.end(); s++){
                push_left(*s);
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
            while(n_ptr->next != nullptr){
                if(n_ptr->elem > n_ptr->next->elem)
                    return false;
                n_ptr = n_ptr->next;
            }
            return true;
        }

        Linkedlist& push_left(T elem){
            Node* n = new Node;
            n->elem = elem;
            n->next = head.next;
            head.next = n;
            ++_size;
            return *this;
        }

        void print(){
                Node* loopPtr = head.next;
                while(loopPtr != nullptr){
                    std::cout << loopPtr->elem << " ";
                    loopPtr = loopPtr->next;
                }
                std::cout << std::endl;
        }

        void call_merge(){
            head.next = merge_sort(head.next);
        }

        Node* merge_sort(Node* n){
            if(n == nullptr || n->next == nullptr)
                return n;
            Node* middle = getMiddle(n);
            Node* left_head = n;
            Node* right_head = middle->next;
            middle->next = nullptr;
            return merge(merge_sort(left_head), merge_sort(right_head));
        }

        Node* getMiddle(Node* n){
            if(n == nullptr)
                return n;
            Node* slow, *fast;
            slow = fast = n;
            while(fast->next != nullptr && fast->next->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node* merge(Node* a, Node* b){
            Node dummyHead;
            Node* current = &dummyHead;
            while(a != nullptr && b != nullptr){
                if(a->elem < b->elem){
                    current->next = a;
                    a = a->next;
                }else{
                    current->next = b;
                    b = b->next;
                }
                current = current->next;
            }
            current->next = (a == nullptr) ? b : a;
            return dummyHead.next;
        }

        Linkedlist(const Linkedlist&) = delete;
        Linkedlist& operator=(const Linkedlist&) const = delete;
        ~Linkedlist(){
            Node* node_to_delete;
            Node* ptr = head.next;
            while(ptr != nullptr){
                node_to_delete = ptr;
                ptr = ptr->next;
                delete node_to_delete;
            }
            
        }

    };
}