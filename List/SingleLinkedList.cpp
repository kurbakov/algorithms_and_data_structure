#include "iostream"

template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <class T>
class SingleLinkedList{
private:
    Node<T>* begin;
    Node<T>* end;
    long long size;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    uint64_t get_size();
    
    void add_front(T x);
    void add_back(T x);
    void print_list();
    void clear();
};

template <class T>
SingleLinkedList<T>::SingleLinkedList() 
{
    this->begin = nullptr;
    this->end = nullptr;
    this->size = 0;
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList<T>() 
{
    // free the memory
    clear();
}

template <class T>
uint64_t SingleLinkedList<T>::get_size() {
    return size;
}

template <class T>
void SingleLinkedList<T>::add_front(T x) {
    Node<T> *new_node = new Node<T>(x);
    if(begin == nullptr){
        begin = new_node;
        end = new_node;
    }
    else{
        new_node->next = begin;
        begin = new_node;
    }
    size++;
    return;
}

template <class T>
void SingleLinkedList<T>::add_back(T x) {
    Node<T> *new_node = new Node<T>(x);
    if(end == nullptr){
        begin = new_node;
        end = new_node;
    }
    else{
        end->next = new_node;
        end = new_node;
    }
    size++;
    return;
}

template <class T>
void SingleLinkedList<T>::print_list() {
    Node<T> *cur = begin;
    while(cur != NULL){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

template <class T>
void SingleLinkedList<T>::clear() {
    Node<T> *cur = begin;
    while(cur != nullptr){
        Node<T> *temp = cur;
        cur = cur->next;
        delete temp;
    }
    begin = nullptr;
    end = nullptr;
    size = 0;
}

//=====================================================================
int main(){

    SingleLinkedList<int> *my_list = new SingleLinkedList<int>();
    
    std::cout << "the size is: " << my_list->get_size() << std::endl;
    my_list->add_front(1);
    my_list->add_front(10);
    my_list->add_front(100);
    
    std::cout << "the size is: " << my_list->get_size() << std::endl;
    my_list->add_back(100);
    my_list->add_back(10);
    my_list->add_back(1);
    
    std::cout << "the size is: " << my_list->get_size() << std::endl;
    my_list->print_list();
    my_list->clear();

    return 0;
}
