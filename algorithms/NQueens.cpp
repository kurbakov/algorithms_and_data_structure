// more info:
// https://en.wikipedia.org/wiki/Eight_queens_puzzle
#include <iostream>

class NQuens{
private:
    int N;
    int* position;

public:
    NQuens(int n){
        N = n;
        position = new int[n];
    }

    ~NQuens(){
        delete[] position;
    }

    bool is_safe(int queen_number, int row_position){
        for (int i = 0; i < queen_number; i++){
            int other_row_pos = position[i];

            if (other_row_pos == row_position ||                        // Same row
                other_row_pos == row_position - (queen_number - i) ||   // Same diagonal
                other_row_pos == row_position + (queen_number - i))     // Same diagonal
                return false;
        }
        return true;
    }

    void add_queen(int k)
    {
        if (k == N){
            // exit recursion
            std::cout << "Solution: ";
            for (int i = 0; i < N; i++){
                std::cout << position[i] << " ";
            }
            std::cout << "\n";
            return;
        }

        // Generate ALL combinations
        for (int i = 0; i < N; i++){ 
            if(is_safe(k, i)){
                position[k] = i;
                add_queen(k + 1);
            }
        }

    }

    void solve(){
        add_queen(0);
    }
};

int main(){
    NQuens nq(8);
    nq.solve();

    return 0;
}