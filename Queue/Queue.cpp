#include "iostream"

namespace DS_Queue{
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
class Queue{
private:
    Node<T>* Front;
    Node<T>* Back;
    uint64_t Size;

public:
    Queue();
    ~Queue();

    bool empty();
    uint64_t get_size();

    T front();
    T back();

    void push(T);
    T pop();
};
}; // namespace

namespace DS_Queue{

template <class T>
Queue<T>::Queue(){
    Front = nullptr;
    Back = nullptr;
    Size = 0;
}

template <class T>
Queue<T>::~Queue(){
    Node<T>* cur = Front;
    while(cur != nullptr){
        Node<T>* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

template <class T>
bool Queue<T>::empty(){
    return Size == 0;
}

template <class T>
uint64_t Queue<T>::get_size(){
    return Size;
}

template <class T>
T Queue<T>::front(){
    return Front->data;

}

template <class T>
T Queue<T>::back(){
    return Back->data;
}

template <class T>
void Queue<T>::push(T v){
    Node<T>* new_node = new Node<T>(v);
    if(Front == nullptr){
        Front = new_node;
        Back = new_node;
    }
    else{
        Front->prev = new_node;
        new_node->next = Front;
        Front = new_node;
    }
    Size++;
    return;
}

template <class T>
T Queue<T>::pop(){
    Node<T>* node_del = Back;
    Back = Back->prev;
    Back->next = nullptr;
    T res = node_del->data;
    delete node_del;
    Size--;
    return res;
}
};

int main(){
    DS_Queue::Queue<int> q;
    std::cout << q.get_size() << "\n";
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    std::cout << q.get_size() << "\n";
    std::cout << q.pop() << "\n";

    std::cout << q.front() << "\n";
    std::cout << q.back() << "\n";

    return 0;
}