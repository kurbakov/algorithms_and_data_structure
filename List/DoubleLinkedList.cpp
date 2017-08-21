#include "iostream"

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;

    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class DoubleLinkedList{
private:
    Node<T>* begin;
    Node<T>* end;
    uint64_t size;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    uint64_t get_size();

    void add_front(T x);
    void add_back(T x);

    void print_list();
    void reverse();

    void delete_front();
    void delete_back();
    void delete_list();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    begin = nullptr;
    end = nullptr;
    size = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    delete_list();
}

template <class T>
void DoubleLinkedList<T>::add_front(T x) {
    Node<T>* new_node = new Node<T>(x);
    if(begin == nullptr){
        begin = new_node;
        end = new_node;
    }
    else{
        begin->prev = new_node;
        new_node->next = begin;
        begin = new_node;
    }
    size++;
    return;
}

template <class T>
void DoubleLinkedList<T>::add_back(T x) {
    Node<T>* new_node = new Node<T>(x);
    if(end == nullptr){
        begin = new_node;
        end = new_node;
    }
    else{
        end->next = new_node;
        new_node->prev = end;
        end = new_node;
    }
    size++;
    return;
}

template <class T>
void DoubleLinkedList<T>::print_list() {
    Node<T>* cur = begin;
    while(cur != nullptr){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <class T>
void DoubleLinkedList<T>::delete_list() {
    Node<T>* cur = begin;
    while(cur != nullptr){
        Node<T>* temp = cur;
        cur = cur->next;
        delete temp;
    }
    begin = nullptr;
    end = nullptr;
    size = 0;
}

template <class T>
uint64_t DoubleLinkedList<T>::get_size() {
    return size;
}

template <class T>
void DoubleLinkedList<T>::reverse() {
    Node<T>* cur = begin;
    while(cur != nullptr){
        Node<T> *tmp = cur->next;
        cur->next = cur->prev;
        cur->prev = tmp;
        if(tmp == nullptr){
            end = begin;
            begin = cur;
        }
        cur = tmp;
    }
    return;
}

template <class T>
void DoubleLinkedList<T>::delete_front(){
    Node<T>* node_del = begin;
    begin = begin->next;
    begin->prev = nullptr;
    delete node_del;
    return;
}

template <class T>
void DoubleLinkedList<T>::delete_back(){
    Node<T>* node_del = end;
    end = end->prev;
    end->next = nullptr;
    delete node_del;
    return;
}

//=====================================================================

int main(){
    DoubleLinkedList<int> *my_list = new DoubleLinkedList<int>();
    my_list->add_back(1);
    my_list->add_back(10);
    my_list->add_back(100);
    my_list->add_front(1000);

    std::cout << "the size is: " << my_list->get_size() << std::endl;
    my_list->print_list();

    my_list->delete_back();
    my_list->print_list();

    my_list->reverse();
    my_list->print_list();

    my_list->delete_list();
    return 0;
}
