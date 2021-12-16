#include<iostream>
#include<climits>
using namespace std;

void dijkstra(int **graph, int n) {
    int distance[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for (int p = 0; p < n; p++) {
        int min = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (min == -1 || distance[j] < distance[min])) {
                min = j;
            }
        }
        visited[min] = true;
        for (int k = 0; k < n; k++) {
            if (graph[min][k] != 0 && (distance[min] + graph[min][k]) < distance[k]) {
                distance[k] = distance[min] + graph[min][k];
            }
        }
    }
    cout << "Vertex     Distance from source" << endl;
    for (int i = 1; i < n; i++) {
        cout << i << "              " << distance[i] << endl;
    }
}

int main() {
    int rows, col;
    cout << "\n\t\tD I J K S T R A\n";
    cout << "\nEnter number of vertices: ";
    cin >> rows;
    col = rows;
    int **graph = new int*[rows];
    for (int i = 0; i < rows; i++) {
        graph[i] = new int[col];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter distance: ";
            cin >> graph[i][j];
        }
    }
    // int graph[5][5] = {
    //                 {0, 5, 0, 10, 15},
    //                 {0, 0, 1, 4, 0},
    //                 {0, 0, 0, 2, 0},
    //                 {0, 3, 0, 0, 0},
    //                 {0, 0, 8, 0, 0}
    //                 };

    // int graph[5][5] = {
    //                 {0, 10, 3, 0 , 0},
    //                 {0, 0, 1, 2, 0},
    //                 {0, 4, 0, 8, 2},
    //                 {0, 0, 0, 0, 7},
    //                 {0 ,0, 0, 9, 0}
    //                 };
    dijkstra(graph, rows);
}