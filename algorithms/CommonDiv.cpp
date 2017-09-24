// more info:
// https://codility.com/media/train/10-Gcd.pdf

#include <iostream>

int GCD(int x, int y){
    if(x%y==0) return y;
    else return GCD(y, x%y);

}

int LCM(int a, int b){
    return (a*b)/GCD(a, b);
}


int main() {
    std::cout << GCD(100, 75) << "\n";
    std::cout << LCM(100, 75) << "\n";
    return 0;
}
