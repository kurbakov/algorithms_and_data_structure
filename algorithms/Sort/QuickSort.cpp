// more info here:
// http://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm
// http://www.algolist.net/Algorithms/Sorting/Quicksort
#include <iostream>

template<typename T>
void QuickSort(T* arr, int left, int right) {
    if(left == right) return;

    int i = left;
    int j = right;
    T pivot = arr[(left + right) / 2];

    while (i < j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        // swap here
        if (i <= j) {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j) QuickSort<T>(arr, left, j);
    if (i < right) QuickSort<T>(arr, i, right);
    
}

template<typename T>
void PrintArray(T* arr, uint64_t Size){
    for(int i=0; i<Size; i++){
        std::cout<< arr[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    uint64_t Size = 14;
    int my_arr[] = {9,8,7,6,5,4,3,2,1,0,11,12,12,13};

    // Size-1 because we define max index in the array that we can reach
    QuickSort<int>(&my_arr[0], 0, Size-1); 
    PrintArray<int>(&my_arr[0], Size);

    return 0;
}