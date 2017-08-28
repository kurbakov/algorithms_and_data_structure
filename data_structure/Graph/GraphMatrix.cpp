#include <iostream>

namespace GraphM{
// T can be int, double but not char or std::string (numbers only)
template <class T> 
class Graph{
private:
    int N;
    T** g;

public:
    Graph(unsigned int);
    ~Graph();

    void add_edge(unsigned int, unsigned int, T);
    void delete_edge(unsigned int, unsigned int);

    void print();
};
}; // namespace

namespace GraphM{
    template <class T>
    Graph<T>::Graph(unsigned int n){
        N = n;
        g = new T*[n];
        for(int i = 0; i < n; ++i){
            g[i] = new T[n];
        }
        for(int k=0; k<N; k++){
            for(int j=0; j<N; j++){
                g[k][j] = 0;
            }
        }
    }

    template <class T>
    Graph<T>::~Graph(){
        for(int i=0; i<N; i++){
            delete[] g[i];
        }
        delete[] g;
    }

    template <class T>
    void Graph<T>::add_edge(unsigned int x, unsigned int y, T w){
        if(x>=N || y>=N) return;
        g[x][y] = w;
    }

    template <class T>
    void Graph<T>::delete_edge(unsigned int x, unsigned int y){
        if(x>=N || y>=N) return;
        g[x][y] = 0;
    }

    template <class T>
    void Graph<T>::print(){
        for(int i=0; i<N; i++){
            std::cout << "[" << i << "]: ";
            for(int j=0; j<N; j++){
                std:: cout << g[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

}; // namespace

int main(){
    GraphM::Graph<int> g(10);
    g.add_edge(1,2,1);
    g.add_edge(3,2,1);
    g.add_edge(5,2,1);
    g.add_edge(7,2,1);

    g.print();
    return 0;
}