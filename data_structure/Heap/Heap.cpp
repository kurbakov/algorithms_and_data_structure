#include <iostream>

namespace DS_Heap{
template<class T>
class Heap{
private:
    T* heap;
    uint64_t Size;
    uint64_t Buffer;

    void fix_insert(int);
    int parent(int);


public:
    Heap();
    ~Heap();

    uint64_t get_size();
    void add_node(T);
    void print_heap();
    void delete_min();
    void delete_max();
};
}; // namespace

namespace DS_Heap{
template<class T>
Heap<T>::Heap() {
    heap = new T[100];
    Buffer = 100;
    Size = 0;
}

template<class T>
Heap<T>::~Heap() {
    delete[] heap;
}

template<class T>
uint64_t Heap<T>::get_size(){ 
    return Size;
}

template<class T>
void Heap<T>::add_node(T v){
    heap[Size] = v;
    fix_insert(Size);
    Size++;
}

template<class T>
void Heap<T>::fix_insert(int x){
    while ( (x>0) && (parent(x)>=0) && (heap[parent(x)]>heap[x]) )
    {
        T temp = heap[parent(x)];
        heap[parent(x)] = heap[x];
        heap[x] = temp;
        x = parent(x);
    }
}

template<class T>
int Heap<T>::parent(int child){
    if (child != 0) {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

template<class T>
void Heap<T>::print_heap(){
    for(unsigned int i=0; i<Size; i++)
        std::cout << heap[i] << " ";
    std::cout << "\n";
}

template<class T>
void Heap<T>::delete_max() {
    Size--;
}

template<class T>
void Heap<T>::delete_min() {
    for(int i=1; i<Size; i++){
        heap[i-1] = heap[i];
    }
    Size--;
}
}; // namespace

int main() {
    DS_Heap::Heap<int> h;
    std::cout << h.get_size() << std::endl;
    h.add_node(3);
    h.add_node(10);
    h.add_node(5);
    h.add_node(1);

    h.print_heap();

    h.delete_max();
    h.delete_min();

    h.print_heap();
    return 0;
}