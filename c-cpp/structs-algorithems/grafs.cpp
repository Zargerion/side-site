#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<int> *adjLists;
    bool *visited;
    bool trigger = true;

public:
    Graph(int V) {
        numVertices = V;
        adjLists = new vector<int>[V];
        visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < adjLists[i].size(); j++) {
                cout << adjLists[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex) {
        visited[vertex] = true;
        if (trigger)
        {
            cout << "DFS traversal: ";
            trigger = false;
        }
        cout << vertex << " ";

        vector<int>::iterator i;
        for (i = adjLists[vertex].begin(); i != adjLists[vertex].end(); i++) {
            if (!visited[*i]) {
                DFS(*i);
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.printGraph();
    g.DFS(0);

    return 0;
}
