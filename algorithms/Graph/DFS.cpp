// http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
#include<iostream>
#include <list>

class Graph
{
    int size;
    std::list<int> *adj;

    void DFSUtil(int, bool[]);

public:
    Graph(int);
    ~Graph();

    void addEdge(int, int);
    void DFS();
};

Graph::Graph(int V)
{
    this->size = V;
    adj = new std::list<int>[V];
}

Graph::~Graph(){
    delete[] adj;
}

void Graph::addEdge(int from, int to)
{
    adj[from].push_back(to);
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << "\n";

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++){
        visited[i] = false;
    }

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < size; i++){
        if (visited[i] == false){
            DFSUtil(i, visited);
        }
    }
}


int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "The result of BFS(2):" << std::endl;
    g.DFS();

    return 0;
}