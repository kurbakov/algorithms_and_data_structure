#include <iostream>

template<typename T>
void insertion_sort(T* Arr, uint64_t Size){
    T temp;
    for (int i=1; i<Size; i++){
        int idx = i;
        while (idx > 0 || Arr[idx-1] > Arr[idx]){
            // swap
            temp = Arr[idx];
            Arr[idx] = Arr[idx-1];
            Arr[idx-1] = temp;
            idx--;
        }
    }
}

template<typename T>
void insertion_sort(T* Arr, uint64_t Size, bool (*Comp)(T, T)){
    T temp;
    for (int i=1; i<Size; i++){
        int idx = i;
        while (idx > 0 && (*Comp)(Arr[idx-1], Arr[idx])){
            // swap
            temp = Arr[idx];
            Arr[idx] = Arr[idx-1];
            Arr[idx-1] = temp;

            // decrease
            idx--;
        }
    }
}

template<typename T>
bool f(T l, T r){
    return l<r;
}


int main(int argc, char const *argv[])
{
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    insertion_sort(&my_array[0], 10, f);

    for(int i=0; i<10; i++){
        std::cout << my_array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}