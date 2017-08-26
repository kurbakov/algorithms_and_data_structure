#include <iostream>
#include <functional>

namespace HashTable{
template<typename T>
struct Node{
    T key;
    Node<T>* Next;

    Node(T data){
        key = data;
        Next = nullptr;
    }
};

template <class T>
class HTable{
private:
    uint64_t BUFFER;
    uint64_t Size;
    Node<T>* Table;

    uint64_t hash_function(T);

public:
    HTable();
    ~HTable();

    void get_size();
    bool is_empty();
    void insert(T key);
    bool find(T key);
    void remove(T key);
};
}; // namespace


namespace HashTable{
template <class T>    
uint64_t HTable<T>::hash_function(T value){
    return std::hash<T>(value) % BUFFER;
}

template <class T>
HTable<T>::HTable(){
    BUFFER = 100;
    Size = 0;
    Table = new Node<T>[BUFFER];
    for(int i=0; i<BUFFER; i++){
        Table[i] = nullptr;
    }
}

template <class T>
HTable<T>::~HTable(){
    delete Table;
}

template <class T>
void HTable<T>::get_size(){
    return Size;
}

template <class T>
bool HTable<T>::is_empty(){
    return Size == 0;
}

template <class T>
void HTable<T>::insert(T key){
    uint64_t idx = hash_function(key);
    if(Table[idx] == nullptr){
        Node<T>* new_node = new Node<T>(key);
        Table[idx] = new_node;
        return;
    }

    Node<T>* cur;
    while(cur->Next != nullptr){
        if(cur->data == key) return;
        cur = cur->Next;
    }
    
    Node<T>* new_node = new Node<T>(key);
    cur->Next = new_node;
    return;
}

template <class T>
bool HTable<T>::find(T key){
    uint64_t idx = hash_function(key);
    Node<T>* cur = Table[idx];

    while (cur != nullptr){
        if(cur->data == key){
            return true;
        }
        else{
            cur = cur->Next;
        }
    }
    return false;
}

template <class T>    
void HTable<T>::remove(T key){}

};
