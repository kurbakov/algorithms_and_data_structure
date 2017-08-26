#include <iostream>
#include <set>
#include <vector>

namespace GraphV{
template <typename T>
struct Vertex{
    T Name;
    std::set<T> Connections;

    Vertex(){}
    Vertex(T v){
        Name = v;
    }

    void print(){
        std::cout << Name << ": ";
    
        for(auto el : Connections){
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
};

template <class T>
class Graph{
private:
    std::vector<Vertex<T>* > g;

public:
    Graph();
    ~Graph();

    void add_vertix(T vertix_name);
    void delete_vertix(T vertix_name);

    void add_edge(T from, T to);
    void delete_edge(T from, T to);

    void print_graph();
};
};// namespace

namespace GraphV{
    template <class T>
    Graph<T>::Graph(){}

    template <class T>
    Graph<T>::~Graph(){
        uint64_t s = g.size();
        for(int i=0; i<s; i++){
            delete g[i];
        }
    }

    template <class T>
    void Graph<T>::add_vertix(T v){
        bool check;
        for(int i=0; i<g.size(); i++){
            if(g[i]->Name == v) check = true;
        }
        if(check) return;

        Vertex<T>* new_vertex = new Vertex<T>(v);
        g.push_back(new_vertex);
    }

    template <class T>
    void Graph<T>::delete_vertix(T v){
        int idx = -1;
        for(int i=0; i<g.size(); i++){
            if(g[i]->Name == v) idx = i;
        }
        if(idx != -1){
            Vertex<T>* del = g[idx];
            delete del;
            g.erase(g.begin()+idx);
        }
        return;
    }

    template <class T>
    void Graph<T>::add_edge(T from, T to){
        if(from == to) return;

        int first = -1, second = -1;
        for(int i=0; i<g.size(); i++){
            if(g[i]->Name == from) first = i;
            if(g[i]->Name == to) second = i;
        }

        if(first != -1 && second != -1){
            g[first]->Connections.insert(to);
        }
        return;
    }

    template <class T>
    void Graph<T>::delete_edge(T from, T to){
        if(from == to) return;
        
        int idx = -1;
        for(int i=0; i<g.size(); i++){
            if(g[i]->Name == from) idx = i;
        }

        if(idx != -1){
            auto it = g[idx]->Connections.find(to);
            g[idx]->Connections.erase(it);
        }
        return;
    }

    template <class T>
    void Graph<T>::print_graph(){
        for(int i=0; i<g.size(); i++){
            g[i]->print();
        }
    }

};// namespace

int main(){
    GraphV::Graph<int> g;
    g.add_vertix(1);
    g.add_vertix(12);
    g.add_vertix(3);
    g.add_vertix(4);

    g.add_edge(1,12);
    g.add_edge(1,4);
    g.add_edge(12,4);
    g.add_edge(3,12);
    g.add_edge(3,1);

    g.print_graph();
    
    return 0;
}