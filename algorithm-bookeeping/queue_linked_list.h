/*

    A Queue based on linked-lists.
    With range-base for loop implemention.

    更新：
    1. 将头指针，改成头节点，头结点不是动态内存
    2. 添加了尾部节点，这样添加元素的时候就不用遍历了。。。

*/

#include <iostream>

namespace ythlearn{
    template<typename T>
    class Queue{
        private:
            class Node{
                friend Queue;
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
            Node tail;
            int _size;

        public:
        Queue():_size(0){
            head.next = tail.next = nullptr;
        }

        explicit Queue(const Queue& q):_size(0){
            head.next = tail.next = nullptr;
            Node* loopPtr = q.head.next;
            while(loopPtr != nullptr){
                enqueue(loopPtr->elem);
                loopPtr = loopPtr->next;
            }
        }

        Queue& enqueue(T item){   //向表尾添加元素
            Node* n = new Node;
            n->elem = item;
            n->next = nullptr;
            if(empty()){
                head.next = tail.next = n;
            }else{
                tail.next->next = n;
                tail.next = n;
            }
            
            _size++;

            return *this;
        }

        T dequeue(){
            if(empty()){   //从表头删除元素
                throw std::runtime_error("Queue is empty, got nothing to dequeue out.");
            }else{
                T item = head.next->elem;
                Node* old_first = head.next;
                head.next = head.next->next;
                delete old_first;
                _size--;
                if(empty()){
                    head.next = tail.next = nullptr;
                }
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

        ~Queue(){
            Node* ele_to_delete;
            while(head.next != nullptr){
                ele_to_delete = head.next;
                head.next = head.next->next;
                delete ele_to_delete;
            }
        }

        // Queue(const Queue&) = delete;
        Queue& operator=(const Queue&) = delete;
    };
}
