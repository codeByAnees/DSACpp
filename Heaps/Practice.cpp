#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int *arr;
    arr = new int[2];
    arr[0] = 1;
    arr[1] = 2;
    int max = arr[0] > arr[1]? 0 : 1;
    int a, b, c;
    a = (1) / 2;
    // b = 9 / 3;
    // c = (a < b)? a : b;
    cout << a;
}