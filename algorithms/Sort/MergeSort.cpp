// more info here:
// http://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm
#include <iostream>

template<typename T>
void merging(T* Arr, T* temp, int low, int mid, int high) {
    int l1, l2, i;

    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if(Arr[l1] <= Arr[l2]){
            temp[i] = Arr[l1++];
        }
        else{
            temp[i] = Arr[l2++];
        }
    }

    while(l1 <= mid) temp[i++] = Arr[l1++];

    while(l2 <= high) temp[i++] = Arr[l2++];

    for(i = low; i <= high; i++){
        Arr[i] = temp[i];
    }
}

template<typename T>
void sort(T* Arr, T* temp, int low, int high) {
    if(low < high){
        int mid = (low + high) / 2;
        sort<T>(Arr, temp, low, mid);
        sort<T>(Arr, temp, mid+1, high);
        merging<T>(Arr, temp, low, mid, high);
    } 
    else{ 
        return;
    }   
}

template<typename T>
void MergeSort(T* Arr, uint64_t Size){
    T* temp = new T[Size-1];
    sort<T>(Arr, temp, 0, Size-1);
    delete[] temp;
}

int main() { 
    int data[] = {9,8,7,6,5,4,3,2,1,0,11,12,13}; 
    MergeSort(&data[0], 13);

    std::cout << "List after sorting" << "\n";
    for(int i = 0; i < 13; i++){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}