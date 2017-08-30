// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
// http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

#include <limits.h>
#include <vector>
#include <iostream>

class Graph{
private:
    int V;
    int** graph;

    int min_distance(std::vector<int>, std::vector<bool>);
    void print_solution(std::vector<int>);

public:
    Graph(int);
    ~Graph();

    void add_edge(int, int, int);
    void delete_edge(int, int);

    void print_graph();
    
    void dijkstra(int);
    int dijkstra(int, int);
};


Graph::Graph(int v) {
    this->V = v;
    graph = new int*[v];
    for(int i=0; i<v; i++){
        graph[i] = new int[v];
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            graph[i][j] = 0;
        }
    }
}

Graph::~Graph(){
    for(int i=0; i<V; i++){
        delete[] graph[i];
    }
    delete[] graph;
}

void Graph::print_graph() {
    for(int i = 0; i<V; i++) {
        for (int k = 0; k < V; k++){
            std::cout << graph[i][k] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::add_edge(int v1, int v2, int weight) {
    if (v1 == v2)
        return;

    graph[v1][v2] = weight;
    graph[v2][v1] = weight;
}

void Graph::delete_edge(int v1, int v2) {
    if (v1 == v2)
        return;

    graph[v1][v2] = 0;
    graph[v2][v1] = 0;
}

/* =================================================== */
int Graph::min_distance(std::vector<int> dist, std::vector<bool> sptSet) {
    // Initialize min value
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v]; 
            min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance array
void Graph::print_solution(std::vector<int> dist) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++){
        std::cout << i << "\t\t" << dist[i] << "\n";
    }
}

void Graph::dijkstra(int src) {
    // The output array.  dist[i] will hold the shortest
    // distance from src to i
    std::vector<int> dist(V, 0);

    // sptSet[i] will true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    std::vector<bool> sptSet(V, false);


    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = min_distance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // print the constructed distance array
    print_solution(dist);
}

int Graph::dijkstra(int from, int to) {
    std::vector<int> dist(V, 0);
    std::vector<bool> sptSet(V, false);

    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[from] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = min_distance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
        if(u == to) return dist[u];
    }

    return -1;
}

int main()
{
    Graph g(9);

    g.add_edge(0,1,4);
    g.add_edge(0,7,8);
    g.add_edge(1,2,8);
    g.add_edge(1,7,11);
    g.add_edge(2,3,7);
    g.add_edge(2,5,4);
    g.add_edge(2,8,2);
    g.add_edge(3,4,9);
    g.add_edge(3,5,14);
    g.add_edge(4,5,10);
    g.add_edge(5,6,2);
    g.add_edge(6,7,1);
    g.add_edge(6,8,6);
    g.add_edge(7,8,7);

    g.print_graph();
    g.dijkstra(0);

    std::cout << g.dijkstra(0,2) << std::endl;

    return 0;
}