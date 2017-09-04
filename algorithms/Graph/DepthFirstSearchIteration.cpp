#include <iostream>
#include <vector>
#include <stack>

class Graph{
private:
    std::vector<std::vector<int> > G;

public:
    Graph(int);
    ~Graph();

    bool add_edge(int, int);
    void add_vertex();
    void print();

    void DFS(int);
};

Graph::Graph(int s)
{
    for(int i=0;i<s;i++)
    {
        std::vector<int> vertex;
        G.push_back(vertex);
    }
}

Graph::~Graph(){}

bool Graph::add_edge(int x, int y)
{
    int s = G.size();
    if(x < s && y < s)
    {
        G[x].push_back(y);
        G[y].push_back(x);
        return true;
    }
    return false;
}

void Graph::add_vertex()
{
    std::vector<int> vertex;
    G.push_back(vertex);
    return;
}

void Graph::print()
{
    int s1 = G.size();
    for(int i = 0; i<s1; i++)
    {
        int s2 = G[i].size();
        std::cout << "[" << i <<"]: ";
        for(int k=0; k<s2; k++){
            std::cout << G[i][k] << " ";
        }
        std::cout << "\n";
    }
    return;
}

void Graph::DFS(int start)
{
    int size = G.size();
    if(start >= size){
        return;
    }

    bool *visited = new bool[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;
    visited[start] = true;

    std::stack<int> s;
    s.push(start);

    std::vector<int>::iterator it;
    while(!s.empty()){
        start = s.top();
        std::cout << start << " ";
        s.pop();

        for(it = G[start].begin(); it != G[start].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                s.push(*it);
            }
        }
    }
    std::cout <<"\n";
    return;
}

int main()
{
    Graph g(7);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,3);
    g.add_edge(2,5);
    g.add_edge(3,6);
    g.add_edge(4,5);
    g.add_edge(4,6);

    g.DFS(0);
    return 0;
}
