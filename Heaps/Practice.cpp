#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int *arr;
    arr = new int[3];
    arr[0] = 1;
    arr[1] = 15;
    arr[2] = 7;
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << largest;
}