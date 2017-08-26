#include <iostream>
#include <functional>

namespace HashTable{
template<typename T>
struct Node{
    T* key;
    Node<T>* Next;

    Node(){
        key = nullptr;
        Next = nullptr;
    }

    Node(T data){
        key = &data;
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

    void print();
    void insert(T key);
    void remove(T key);

    bool find(T key);
};
}; // namespace


namespace HashTable{
template <class T>    
uint64_t HTable<T>::hash_function(T value){
    return std::hash<T>()(value) % BUFFER;
}

template <class T>
HTable<T>::HTable(){
    BUFFER = 100;
    Size = 0;
    Table = new Node<T>[BUFFER];
}

template <class T>
HTable<T>::~HTable(){
    for(int i=0; i<BUFFER; i++){
        if(Table[i].Next != nullptr){
            Node<T>* cur = Table[i].Next;
            while(cur != nullptr){
                Node<T>* del = cur;
                cur=cur->Next;
                delete del;
            }
        }
    }
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

template<class T>
void HTable<T>::print(){
    for(int i=0; i<BUFFER; i++){
        if(Table[i].key != nullptr){
            Node<T>* cur = &Table[i];
            while(cur != nullptr){
                std::cout << *cur->key << " ";
                cur = cur->Next;
            }
            std::cout << "\n";
        }
    }
}

template <class T>
void HTable<T>::insert(T v){
    uint64_t idx = hash_function(v);
    if(Table[idx].key == nullptr){
        Table[idx].key = &v;
        return;
    }

    Node<T>* cur = &Table[idx];
    while(cur->key != nullptr){
        if(cur->key == &v) return;
        cur = cur->Next;
    }

    Node<T>* new_node = new Node<T>(v);
    cur->Next = new_node;
    return;
}

template <class T>    
void HTable<T>::remove(T v){
    uint64_t idx = hash_function(v);
    if(*Table[idx].key == v){
        Table[idx].key = nullptr;
        return;
    }
    Node<T>* cur = &Table[idx];
    while(cur->Next != nullptr){
        if(*cur->Next->key == v){
            Node<T>* del = cur->Next;
            cur->Next = del->Next;
            delete del;
            return;
        }
        cur = cur->Next;
    }

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

}; // namespace

int main(){
    HashTable::HTable<int> ht;
    ht.insert(1);
    ht.insert(10);
    ht.print();
    ht.remove(1);
    ht.print();
    
    return 0;
}
