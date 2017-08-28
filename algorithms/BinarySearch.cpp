#include <iostream>

template <typename T>
bool binary_search(T* Data, uint64_t Size, T element){
    if(Size == 0) return -1;

    int lower = 0;
    int higher = Size;
    int mid;

    while(higher >= lower){
        mid = lower + (higher-lower)/2;

        if(element == Data[mid]){
            return true;
        }
        else if(element > Data[mid]){
            lower = mid+1;
        }
        else if(element < Data[mid]){
            higher = mid-1;
        }
    }
    return false;
}

template <typename T>
bool binary_search(T* Data, uint64_t Size, T element, int (*Comp)(T, T)){
    int lower=0;
    int higher=Size;
    int mid;

    while(higher >= lower){
        mid = lower + (higher-lower)/2;

        if((*Comp)(element, Data[mid])==0){
            return true;
        }
        else if((*Comp)(element, Data[mid])==1){
            lower = mid+1;
        }
        else if((*Comp)(element, Data[mid])==-1){
            higher = mid-1;
        }
    }
    return false;
}

template <typename T>
int f(T l, T r){
    if(l == r) return 0;
    else if(l > r) return 1;
    else return -1;
}

int main(){
    int* d = new int[10];
    for(int i =0; i<10; i++){
        d[i] = i;
    }

    if(binary_search(d, 10, 1, f)){
        std::cout << "found" << "\n";
    }
    else{
        std::cout << "not found" << "\n";
    }

    delete[] d;
    return 0;
}