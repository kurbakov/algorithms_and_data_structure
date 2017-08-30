// more info here:
// implementation of the algorithm from here
// http://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm
#include <iostream>

template<typename T>
void shell_sort(T* Arr, uint64_t Size){
    int interval = 1;
    while (interval < Size/3) interval = interval*3+1;

    while(interval>0){
        for(int i = interval; i < Size; i++) {
            T min = Arr[i];
            int inner = i;
            while (inner > interval-1 && Arr[inner-interval] > min) {
                Arr[inner] = Arr[inner-interval];
                inner = inner-interval;
            }
            Arr[inner] = min;
        }
        interval = (interval-1)/3;
    }
}

template<typename T>
void PrintArray(T* Arr, uint64_t Size){
    for(int i=0; i<Size; i++){
        std::cout << Arr[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    int my_array[] = {9,8,7,6,5,4,3,2,1,0};
    PrintArray<int>(&my_array[0], 10);
    shell_sort<int>(&my_array[0], 10);
    PrintArray<int>(&my_array[0], 10);

    return 0;
}