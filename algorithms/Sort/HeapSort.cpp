#include <iostream>

// http://quiz.geeksforgeeks.org/heap-sort/
// https://en.wikipedia.org/wiki/Heapsort

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template <typename T>
void heapify(T* Arr, uint64_t n, uint64_t i)
{
    uint64_t largest = i;  // Initialize largest as root
    uint64_t l = 2*i + 1;  // left = 2*i + 1
    uint64_t r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && Arr[l] > Arr[largest]){
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && Arr[r] > Arr[largest]){
        largest = r;
    }

    // If largest is not root
    if (largest != i){
        std::swap(Arr[i], Arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(Arr, n, largest);
    }
}

// main function to do heap sort
template <typename T>
void heap_sort(T* Arr, uint64_t Size)
{
    // Build heap (rearrange array)
    for (int i = Size / 2 - 1; i >= 0; i--){
        heapify(Arr, Size, i);
    }

    // One by one extract an element from heap
    for (int i=Size-1; i>=0; i--){
        // Move current root to end
        std::swap(Arr[0], Arr[i]);

        // call max heapify on the reduced heap
        heapify(Arr, i, 0);
    }
}

template<typename T>
void print_array(T* Arr, uint64_t Size){
    for(int i=0; i<Size; i++){
        std::cout<< Arr[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    int my_arr [] = {9,8,7,6,5,4,3,2,1,0};
    heap_sort(&my_arr[0], 10);
    print_array(my_arr, 10);

    return 0;
}