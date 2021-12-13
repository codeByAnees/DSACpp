#include<iostream>
#include<climits>
#include <cstdio>
#include <deque>
using namespace std;

// int min(int distance[]) {
//     int min = 0;
//     for (int i = 1; i < distance.length(); i++) {
//         if (distance[min] < distance[i]) {
//             if (!visited[i]) {
//                 min = i;
//             }
//         }
//     }
//     return min;
// }

bool checker(int i, int *vertices) {
    bool val = false;
    for (int j = 0; j < 7; j++) {
        if (vertices[j] == i) {
            val = true;
        }
    }
    return val;
}

bool checker2(int i, int *edge) {
    bool val = false;
    for (int j = 0; j < 7; j++) {
        if (edge[j] == i) {
            val = true;
        }
    }
    return val;
}

void kruskal(int graph[][8], int n) {
    int distance[n * n];
    int parent[n * n];
    int connect[n * n];
    bool visited[n * n];

    int vertices[n - 1];
    int edge[n - 1];
    int dist[n - 1];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        parent[i] = INT_MAX;
        connect[i] = INT_MAX;
        visited[i] = false;
    }
    int count = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                distance[++count] = graph[i][j];
                parent[++count] = i;
                connect[++count] = j;
            }
        }
    }    
    int num = 1;
    while (num <= n - 1) {
        int min = 0;
        for (int i = 1; i < distance.length(); i++) {
            if (distance[min] < distance[i]) {
                if (!visited[i]) {
                    min = i;
                }
            }
        }
        int smallest = min;
        visited[smallest] = true;
        int aParent = parent[smallest];
        int bEdge = connect[smallest];
        int distan = distance[smallest];
        if ((checker(bEdge, vertices) == true && checker2(aParent, edge) == true) && (graph[aParent][bEdge] == graph[bEdge][aParent])) {
            continue;
        }
        else if (checker2(aParent, edge) == true && checker2(bEdge, edge) == true) {
            continue;
        }
        else if (checker(aParent, vertices) == true && checker2(bEdge, edge) == true) {
            continue;
        }
        else {
            vertices[num] = aParent;
            edge[num] = bEdge;
            dist[num] = distan;
            num++;
        }
    }

    cout<<"Edges \tWeight\n";
    for (int i = 0; i < n - 1; i++) {
        cout << vertices[i] << " - " << edge[i] << " \t" << dist[i] << endl;
    }
}

int main() {
    int arr[8][8] = {
        {0,8,0,0,0,10,0,5},
        {8,0,4,0,4,4,0,4},
        {0,4,0,3,0,3,0,0},
        {0,0,3,0,1,6,2,0},
        {0,4,0,1,0,0,3,0},
        {10,4,3,6,0,0,0,0},
        {0,0,0,2,3,0,0,3},
        {5,4,0,0,0,0,3,0}
    };
    kruskal(arr, 8);
}