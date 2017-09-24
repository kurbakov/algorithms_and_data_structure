// more info:
// https://codility.com/media/train/8-PrimeNumbers.pdf
// https://codility.com/media/train/9-Sieve.pdf

#include <iostream>
#include <vector>

// print all divisors of X
void Divisors(int x){
    int i=1;
    while(i*i <= x){
        if (x%i == 0){
            std::cout << i << " " << x/i << "\n";
        }
        i++;
    }
    if(i*i == x){
        std::cout << i << " " << i << "\n";
    }
}

// check if X is a prime number
bool IsPrime(int x){
    int i=2;
    while(i*i <= x){
        if(x%i == 0) return false;
        i++;
    }
    return true;
}

// find all prime numbers from 0 to X
void AllPrime(int x){
    bool* sieve = new bool[x+1];
    for(int i=0; i<x; i++)
        sieve[i] = true;

    sieve[0] = sieve[1] = false;
    int i=2;
    while(i*i <= x){
        if(sieve[i]){
            int k = i*i;
            while(k <= x){
                sieve[k] = false;
                k += i;
            }
        }
        i++;
    }
    for(int k=0; k<x; k++){
        if(sieve[k]){
            std::cout << k <<" ";
        }
    }
    std::cout << "\n";
    delete[] sieve;
}

// find all prime number such as a product of prime numbers = X
std::vector<int> arrayF(int n){
    std::vector<int> F(n+1, 0);

    int i=2;
    while (i*i <= n) {
        int k;
        if (F[i] == 0)
            k = i * i;

        while (k <= n) {
            if (F[k] == 0)
                F[k] = i;
            k += i;
        }
        i++;
    }

    return F;
}

std::vector<int> factorization(int x) {
    auto F = arrayF(x + 1);
    std::vector<int> primeFactors;

    while (F[x] > 0) {
        primeFactors.push_back( F[x] );
        x /= F[x];
    }
    primeFactors.push_back(x);
    return primeFactors;
}


int main() {
    Divisors(100);
    std::cout << IsPrime(17) << "\n";
    std::cout << IsPrime(170) << "\n";
    AllPrime(100);

    auto res = factorization(123);
    for(auto el : res){
        std::cout << el << " ";
    }
    std::cout << "\n";

    return 0;
}
