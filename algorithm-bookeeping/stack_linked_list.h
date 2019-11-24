/*

    A Stack based on linked-lists.
    With range-base for loop implemention.

    更新：
    1. 将头指针，改成头节点，头结点不是动态内存

*/

#include <iostream>

namespace ythlearn{
    template<typename T>
    class Stack{
    private:
        class Node{
            friend Stack;
        public:
            void operator++(){
                this->next = this->next->next;  
            }

            bool operator!=(const Node& rhs){
                return !(*this == rhs);
            }

            T operator*(){
                return this->next->elem; 
            }

            bool operator==(const Node& rhs){
                return this->next == rhs.next;
            }

        private:
            T elem;
            Node* next;
        
        };

        Node head;
        int _size;

    public:
        Stack():_size(0){
            head.next = nullptr;
        }
        
        Stack(const Stack& rhs):_size(0){
            head.next = nullptr;
            Node* loopPtr = rhs.head.next;
            while(loopPtr != nullptr){
                push(loopPtr->elem);
                loopPtr = loopPtr->next;
            }
        }

        void push(T item){
            Node* n = new Node;
            n->elem = item;
            n->next = head.next;
            head.next = n;
            _size++;
        }

        T pop(){
            if(empty()){
                throw std::runtime_error("Stack is emppty, got nothing to pop out.");
            }else{
                T item = head.next->elem;
                Node* old_first = head.next;
                head.next = head.next->next;
                delete old_first;
                _size--;
                return item;
            }
        }

        int size(){
            return _size;
        }

        bool empty(){
            return _size == 0;
        }

        Node begin(){
            return head;
        }

        Node end(){
            Node m;
            m.next = nullptr;
            return m;
        }

        ~Stack(){
            Node* ele_to_delete;
            while(head.next != nullptr){
                ele_to_delete = head.next;
                head.next = head.next->next;
                delete ele_to_delete;
            }
        }

        // Stack(const Stack&) = delete;
        Stack& operator=(const Stack&) = delete;
    };
}

