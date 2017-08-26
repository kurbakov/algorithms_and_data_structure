// Source: http://www.sourcetricks.com/2011/06/c-heaps.html
// Info: https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm

#include <iostream>
#include "vector"

namespace DS_Heap{
template<class T>
class Heap{
private:
    std::vector<T> heap;
    void fix_insert(int);
    int parent(int);

public:
    Heap();
    ~Heap();

    int get_size();
    void add_node(T);
    void print_heap();
    void delete_min();
    void delete_max();
};
}; // namespace

namespace DS_Heap{
template<class T>
Heap<T>::Heap() {}

template<class T>
Heap<T>::~Heap() {}

template<class T>
int Heap<T>::get_size() { return heap.size();}

template<class T>
void Heap<T>::add_node(T v) {
    heap.push_back(v);
    fix_insert(heap.size() - 1);
}

template<class T>
void Heap<T>::fix_insert(int x) {
    while ( (x>0) && (parent(x)>=0) && (heap[parent(x)]>heap[x]) )
    {
        int tmp = heap[parent(x)];
        heap[parent(x)] = heap[x];
        heap[x] = tmp;
        x = parent(x);
    }
}

template<class T>
int Heap<T>::parent(int child) {
    if (child != 0) {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

template<class T>
void Heap<T>::print_heap() {
    for(unsigned int i=0;i<heap.size();i++)
        std::cout << heap[i] << " ";
    std::cout<<std::endl;
}

template<class T>
void Heap<T>::delete_max() {
    heap.pop_back();
}

template<class T>
void Heap<T>::delete_min() {
    heap.erase(heap.begin());
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