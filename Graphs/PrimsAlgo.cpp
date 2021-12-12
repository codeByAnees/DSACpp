#include<iostream>
#include<climits>
using namespace std;

void prims(int graph[][5], int n) {
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
            if (graph[min][k] != 0 && (graph[min][k]) < distance[k]) {
                distance[k] = graph[min][k];
            }
        }
    }
    cout << "Vertex     Distance from source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "              " << distance[i] << endl;
    }
}

int main() {
    // int rows = 5; 
    // int col = 5;
    //int arr[9][9];
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << "Enter a value: ";
    //         cin >> arr[i][j];
    //     }
    // }
    // int arr[9][9] = { 
    //             {0, 4, 0, 0, 0, 0, 0, 8, 0},
    //             {4, 0, 8, 0, 0, 0, 0, 11, 0},
    //             {0, 8, 0, 7, 0, 4, 0, 0, 2},
    //             {0, 0, 7, 0, 9, 14, 0, 0, 0},
    //             {0, 0, 0, 9, 0, 10, 0, 0, 0},
    //             {0, 0, 4, 14, 10, 0, 2, 0, 0},
    //             {0, 0, 0, 0, 0, 2, 0, 1, 6},
    //             {8, 11, 0, 0, 0, 0, 1, 0, 7},
    //             {0, 0, 2, 0, 0, 0, 6, 7, 0} 
    //             };
    // int arr[5][5] = {
    //                 {0, 5, 0, 10, 15},
    //                 {0, 0, 1, 4, 0},
    //                 {0, 0, 0, 2, 0},
    //                 {0, 3, 0, 0, 0},
    //                 {0, 0, 8, 0, 0}
    //                 };

    // int arr[5][5] = {
    //     {0, 10, 3, 0 , 0},
    //     {0, 0, 1, 2, 0},
    //     {0, 4, 0, 8, 2},
    //     {0, 0, 0, 0, 7},
    //     {0 ,0, 0, 9, 0}
    // };

    int arr[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    prims(arr, 5);
}