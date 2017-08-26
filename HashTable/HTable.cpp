#include <iostream>

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
    uint64_t Buffer;
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
uint64_t HTable<T>::hash_function(T value){}

template <class T>
HTable<T>::HTable(){}

template <class T>
HTable<T>::~HTable(){}

template <class T>
void HTable<T>::get_size(){}

template <class T>
bool HTable<T>::is_empty(){}

template <class T>
void HTable<T>::insert(T key){}

template <class T>
bool HTable<T>::find(T key){}

template <class T>    
void HTable<T>::remove(T key){}
};
