// http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
#include<iostream>
#include <list>

class Graph
{
    int size;    
    std::list<int> *adj;  

public:
    Graph(int); 
    ~Graph();

    void addEdge(int, int); 
    void BFS(int); 
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

void Graph::BFS(int start)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push_back(start);

    // 'i' will be used to get all adjacent vertices of a vertex
    std::list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        start = queue.front();
        std::cout << start << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[start].begin(); i != adj[start].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    std::cout << "\n";
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
    g.BFS(2);

    return 0;
}