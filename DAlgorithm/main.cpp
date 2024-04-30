#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

class Graph {
private:
    int V; 
    std::vector<std::vector<int>> edges; 
public:
    Graph(int vertices) : V(vertices), edges(vertices, std::vector<int>(vertices, 0)) {}

    void addEdge(int u, int v, int weight) {
        if (u == v)
        {
            cout << "Edge can`t have two similar vertexes!" << endl;
            return;
        }

        if (weight < 0)
        {
            cout << "Invalid weight" << endl;
            return;
        }

        edges[u][v] = weight;
        edges[v][u] = weight; 
    }

    int getEdgeWeight(int u, int v) {
        return edges[u][v];
    }

    int minDistance(const std::vector<int>& dist, const std::vector<bool>& shortestPathSet) {
        int min = numeric_limits<int>::max(), min_index = -1;

        for (int v = 0; v < V; ++v) {
            if (!shortestPathSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        return min_index;
    }

    int dijkstra(int src) {
        vector<int> dist(V, numeric_limits<int>::max()); 
        vector<bool> shortestPathSet(V, false); 

        dist[src] = 0; 

        for (int count = 0; count < V - 1; ++count) {
            int u = minDistance(dist, shortestPathSet); 
            shortestPathSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!shortestPathSet[v] && edges[u][v] && dist[u] != std::numeric_limits<int>::max() &&
                    dist[u] + edges[u][v] < dist[v]) {
                    dist[v] = dist[u] + edges[u][v];
                }
            }
        }

        cout << "Vertex   Distance\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << dist[i] << '\n';
        }

        int max = 0;
        for (int i = 1; i < V; ++i)
        {
            if (dist[max] < dist[i])
                max = i;
        }

        return dist[max];
    }
};

int main() {
    cout << "Enter quantity of vertexes: ";
    int v; 
    cin >> v;

    Graph g(v);
    string input;
    while (true) {
        cout << "Enter edge in format (start_vertex end_vertex weight), or type 'done' to finish: ";
        cin >> input;

        if (input == "done") break;

        int start = stoi(input);
        cin >> input; 
        int end = stoi(input);
        cin >> input; 
        int weight = stoi(input);

        g.addEdge(start, end, weight);
    }

    cout << "The shortest way from your vertex to the last one weighs: " << g.dijkstra(0);

    return 0;
}
