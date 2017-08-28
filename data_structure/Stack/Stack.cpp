#include "iostream"

namespace DS_Stack{
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
class Stack{
private:
    Node<T>* Front;
    Node<T>* Back;
    uint64_t Size;

public:
    Stack();
    ~Stack();

    bool empty();
    uint64_t get_size();

    T front();
    T back();

    void push(T);
    T pop();
};
}; // namespace

namespace DS_Stack{

    template <class T>
    Stack<T>::Stack(){
        Front = nullptr;
        Back = nullptr;
        Size = 0;
    }

    template <class T>
    Stack<T>::~Stack(){
        Node<T>* cur = Front;
        while(cur != nullptr){
            Node<T>* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }

    template <class T>
    bool Stack<T>::empty(){
        return Size == 0;
    }

    template <class T>
    uint64_t Stack<T>::get_size(){
        return Size;
    }

    template <class T>
    T Stack<T>::front(){
        return Front->data;
    }

    template <class T>
    T Stack<T>::back(){
        return Back->data;
    }

    template <class T>
    void Stack<T>::push(T v){
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
    T Stack<T>::pop(){
        Node<T>* node_del = Front;
        Front = Front->next;
        Front->prev = nullptr;
        T res = node_del->data;
        delete node_del;
        Size--;
        return res;
    }

}; // namespace


int main(){
    DS_Stack::Stack<int> s;
    std::cout << s.get_size() << "\n";
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    std::cout << s.get_size() << "\n";
    std::cout << s.pop() << "\n";

    std::cout << s.front() << "\n";
    std::cout << s.back() << "\n";

    return 0;
}