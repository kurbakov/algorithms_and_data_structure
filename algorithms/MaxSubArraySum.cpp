// more info:
// https://codility.com/media/train/7-MaxSlice.pdf

#include <iostream>

int MaxSubArraySum(int* Array, int Size){
    int max_ending=0;
    int max_slice=0;
    for(int i=0; i<Size; i++){
        max_ending = std::max(0, max_ending + Array[i]);
        max_slice = std::max(max_slice, max_ending);
    }
    return max_slice;
}

int main() {
    int arr[7] = {5, -7, 3, 5, -2, 4};
    std::cout << MaxSubArraySum(&arr[0], 7) << "\n";
    return 0;
}
