#include <iostream>

template<typename T>
void bubble_sort(T* Arr, uint64_t Size, bool (*Comp)(T,T)){
    T temp;
    for (int j=0; j < Size; j++) {
        for (int i = 0; i < Size - 1 - j; i++) {

            if ((*Comp)(Arr[i], Arr[i+1])) {
                temp = Arr[i+1];
                Arr[i+1] = Arr[i];
                Arr[i] = temp;
            }

        }
    }
}

template <typename T>
bool f(T a, T b){
    return a>b;
}

int main()
{
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    bubble_sort(&my_array[0], 10, f);

    for(int i=0; i<10; i++){
        std::cout << my_array[i] << " ";
    }
    std::cout <<"\n";

    return 0;
}