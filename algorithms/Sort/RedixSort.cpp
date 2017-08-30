// more info here:
// Source: http://www.geeksforgeeks.org/radix-sort/
#include <iostream>

template<typename T>
void counting_sort(T* Arr, uint64_t Size, T exp){

    // sorted array (in the future sorted)
    T* output = new T[Size];
    
    // count if made only in the range 0,...,9
    T count[10];

    // count elements
    for(uint64_t i=0;i<Size;i++)
        count[ (Arr[i]/exp)%10 ]++;

    // rebuild index vector to make it incremental
    for(int i=1; i<10; i++)
        count[i] = count[i-1]+count[i];

    // populate target vector
    for(uint64_t i=0; i<Size; i++){
        output[count[ (Arr[i]/exp)%10 ] - 1] = Arr[i];
        count[ (Arr[i]/exp)%10 ]--;
    }

    // copy results to v
    for(uint64_t i=0;i<Size;i++){
        Arr[i] = output[i];
    }
}

template<typename T>
void radix_sort(T* data, uint64_t Size){

    // Find the maximum number to know number of digits
    T max_value = data[0];
    for(uint64_t i=1; i<Size; i++){
        if(data[i]> max_value){
            max_value = data[i];
        }
    }

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (T exp = 1; max_value/exp > 0; exp *= 10){
        counting_sort<T>(data, Size, exp);
    }
}

int main() {
    int vec[] = {1,4,1,2,7,5,2};
    radix_sort<int>(&vec[0], 7);

    for(unsigned int i=0; i<7; i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";

    return 0;
}