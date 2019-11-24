#pragma once

namespace ythlearn{
    template<typename Key, typename Value>
    class SequentialSearchST{
        public:

            class Node{
                public:
                    Key key;
                    Value value;
                    Node* next;
                    Node(Key key, Value value, Node* next):key(key), value(value), next(next){}
                    Node():key(0), value(0), next(nullptr){}
            }

            void put(Key key, Value, value){
                for(Node* x = &first; x != nullptr; x = x->next){
                    if(x->key == key){
                        x->value = value;
                        return;
                    }
                }
                Node
            }

            ~SequentialSearchST(){
             
            }

            SequentialSearchST(const SequentialSearchST&) = delete;
            SequentialSearchST& operator=(const SequentialSearchST&) const = delete; 

        private:
            Node first;
    };
}