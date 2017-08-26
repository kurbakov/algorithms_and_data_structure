#include <iostream>
#include <functional>

namespace HashTable{
template<typename T>
struct Node{
    T key;
    Node<T>* Next;
    
    Node(){};
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
    bool* is_free;

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
    is_free = new bool[BUFFER];
    for(int i=0; i<BUFFER; i++){
        is_free[i] = true;
    }
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
    delete[] Table;
    delete[] is_free;
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
        if(!is_free[i]){
            Node<T>* cur = &Table[i];
            while(cur != nullptr){
                std::cout << cur->key << " ";
                cur = cur->Next;
            }
            std::cout << "\n";
        }
    }
}

template <class T>
void HTable<T>::insert(T v){
    uint64_t idx = hash_function(v);
    if(is_free[idx]){
        Table[idx].key = v;
        is_free[idx] = false;
        return;
    }
    else{
        Node<T>* new_node = new Node<T>(v);
        new_node->Next = Table[idx].Next;
        Table[idx].Next = new_node;
    }
    return;
}

template <class T>    
void HTable<T>::remove(T v){
    uint64_t idx = hash_function(v);
    if(is_free[idx]) return;

    if(Table[idx].key == v && Table[idx].Next == nullptr){
        is_free[idx] = true;
        return;
    }

    Node<T>* cur = &Table[idx];
    while(cur != nullptr){
        if(cur->key == v){
            while(cur->Next != nullptr){
                cur->key = cur->Next->key;
            }

            Node<T>* del = cur->Next;
            cur->Next = nullptr;
            delete del;
            return;
        }
        cur = cur->Next;
    }
}

template <class T>
bool HTable<T>::find(T v){
    uint64_t idx = hash_function(v);
    if(is_free[idx]) return false;

    Node<T>* cur = &Table[idx];
    while (cur != nullptr){
        if( cur->key == v){
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
    ht.remove(1);

    ht.print();

    if(ht.find(10) == true){
        std::cout << "found" <<"\n";
    }

    if(ht.find(1) == false){
        std::cout << "not found" << "\n";
    }
    
    return 0;
}
