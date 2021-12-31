#include<iostream>
#include<climits>
#include<cstdio>
#include<deque>
using namespace std;

int n;
bool vertixChecker(int i, int *vertices) {
    bool val = false;
    for (int j = 0; j < n; j++) {
        if (vertices[j] == i) {
            val = true;
        }
    }
    return val;
}

bool edgeChecker(int i, int *edge) {
    bool val = false;
    for (int j = 0; j < n; j++) {
        if (edge[j] == i) {
            val = true;
        }
    }
    return val;
}

void kruskal(int graph[][8]) {
    int size = n * n;
    int distance[size];
    int parent[size];
    int connect[size];
    bool visited[size];

    for (int i = 0; i < size; i++) {
        distance[i] = INT_MAX;
        parent[i] = INT_MAX;
        connect[i] = INT_MAX;
        visited[i] = false;
    }

    int count = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INT_MAX) {
                count++;
                distance[count] = graph[i][j];
                parent[count] = i;
                connect[count] = j;
            }
        }
    }

    int vertices[n];
    int edge[n];
    int dist[n];

    int num = 1;
    while (num <= n - 1) {
        int smallest = 0;
        for (int i = 1; i < count; i++) {
            if (distance[i] < distance[smallest]) {
                if (!visited[i]) {
                    smallest = i;
                }
            }
        }
        visited[smallest] = true;
        int vertix = parent[smallest];
        int Edge = connect[smallest];
        int dis = distance[smallest];
        if ((vertixChecker(Edge, vertices) && edgeChecker(vertix, edge)) && (graph[vertix][Edge] == graph[Edge][vertix])) {
            continue;
        }
        else if (edgeChecker(vertix, edge) && edgeChecker(Edge, edge)) {
            continue;
        }
        else if (vertixChecker(vertix, vertices) && edgeChecker(Edge, edge)) {
            continue;
        }
        else {
            vertices[num] = vertix;
            edge[num] = Edge;
            dist[num] = dis;
        }
        num++;
    }

    cout<<"Edges \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << vertices[i] << " - " << edge[i] << " \t" << dist[i] << endl;
    }
}

int main() {
    // int rows, col;
    // cout << "\n\t\tK R U S K A L\n";
    // cout << "\nEnter number of vertices: ";
    // cin >> rows;
    // col = rows;
    // int **graph = new int*[rows];
    // for (int i = 0; i < rows; i++) {
    //     graph[i] = new int[col];
    // }
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << "Enter distance: ";
    //         cin >> graph[i][j];
    //     }
    // }
    n = 8;
    int graph[8][8] = {
        {0, 8, 0, 0, 0, 10, 0, 5},
        {8, 0, 4, 0, 4, 4, 0, 4},
        {0, 4, 0, 3, 0, 3, 0, 0},
        {0, 0, 3, 0, 1, 6, 2, 0},
        {0, 4, 0, 1, 0, 0, 3, 0},
        {10, 4, 3, 6, 0, 0, 0, 0},
        {0, 0, 0, 2, 3, 0, 0, 3},
        {5, 4, 0, 0, 0, 0, 3, 0}
    };
    kruskal(graph);
}