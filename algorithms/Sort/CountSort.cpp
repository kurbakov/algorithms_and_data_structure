#include <iostream>

template <typename T>
void counting_sort(T* Arr, uint64_t Size){
    if(Size < 2) return;

    // step 1: find max element
    T max_element = Arr[0];
    T min_element = Arr[0];

    for(int i=1; i<Size; i++){
        if(Arr[i] > max_element) max_element = Arr[i];
        if(Arr[i] < min_element) min_element = Arr[i];
    }

    // step 2: create vector to count with 0 value
    uint64_t count_size = (max_element-min_element)+1;
    int* index = new int[count_size];
    for(int i=0; i<count_size; i++) 
        index[i] = 0;

    // step 3: count elements
    for(int i=0; i<Size; i++) 
        index[Arr[i]-min_element]++;

    // rebuild index vector to make it incremental
    for(int i=1; i<count_size; i++)
        index[i] = index[i-1] + index[i];

    // create empty copy
    T* temp_copy = new T[Size];

    // populate target vector
    for(int i=0; i<Size; i++){
        index[Arr[i]-min_element]--;
        temp_copy[index[Arr[i]-min_element]] = Arr[i];
    }

    // copy
    for(int i=0; i<Size; i++){
        Arr[i] = temp_copy[i];
    }
    delete[] temp_copy;
}


int main() {
    int vec[] = {1,4,1,2,7,5,2};
    counting_sort(&vec[0], 7);

    for(int i=0; i<7; i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    return 0;
}