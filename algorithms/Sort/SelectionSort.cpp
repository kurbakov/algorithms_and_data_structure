#include <iostream>

template <typename T>
void selection_sort(T* arr, uint64_t Size){
    T temp;
    for (int i=0; i<Size-1; i++){
        int min_idx = i;
        for (int j=i+1; j<Size; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }

        if(min_idx != i){
            // swap
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

template <typename T>
void selection_sort(T* arr, uint64_t Size, bool (*Comp)(T, T)){
    T temp;
    for (int i=0; i<Size-1; i++){
        int min_idx = i;
        for (int j=i+1; j<Size; j++){
            if((*Comp)(arr[j], arr[min_idx])){
                min_idx = j;
            }
        }

        if(min_idx != i){
            // swap
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

template <typename T>
bool f(T l, T r){
    return l<r;
}

int main(int argc, char const *argv[])
{
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    selection_sort(&my_array[0], 10, f);

    for(int i=0; i<10; i++){
        std::cout << my_array[i] << " ";
    }
    std::cout <<"\n";

    return 0;
}