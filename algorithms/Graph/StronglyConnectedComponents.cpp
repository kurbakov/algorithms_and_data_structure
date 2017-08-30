// C++ Implementation of Kosaraju's algorithm to print all SCCs
// http://www.geeksforgeeks.org/strongly-connected-components/

#include <iostream>
#include <list>
#include <stack>

class Graph {
private:
    // No. of vertices
    int V;

    // An array of adjacency lists
    std::list<int> *adj;

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing time
    void fillOrder(int, bool[], std::stack<int>&);

    // A recursive function to print DFS starting from v
    void DFSUtil(int, bool[]);

public:
    Graph(int);
    ~Graph();

    void addEdge(int, int);

    // The main function that finds and prints strongly connected components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

Graph::~Graph(){
    delete[] adj;
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[]) {

    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, visited);
        }
    }
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        // Recur for all the vertices adjacent to this vertex
        std::list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            g.adj[*i].push_back(v);
        }

    }
    return g;
}

void Graph::addEdge(int v, int w) {
    // Add w to v’s list.
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], std::stack<int> &Stack) {
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    std::list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i){
        if(!visited[*i]){
            fillOrder(*i, visited, Stack);
        }
    }

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prints all strongly connected components
void Graph::printSCCs() {
    std::stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            fillOrder(i, visited, Stack);
        }
    }

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    // Now process all vertices in order defined by Stack
    while (!Stack.empty()) {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (!visited[v]) {
            gr.DFSUtil(v, visited);
            std::cout << std::endl;
        }
    }
}

// Driver program to test above functions
int main() {
    
    // Create a graph given in the above diagram
    Graph g(5);
    
    // Adding edges to the graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    // print strong connected components
    g.printSCCs();

    return 0;
}