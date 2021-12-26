#include<iostream>
using namespace std;

class sort {
    public:
    int *arr;
    int size;

    sort() {
        int x;
        cout << "Enter length of list: ";
        cin >> x;
        size = x;
        arr = new int[size];
    }

    void bubbleSort(int array[]) {
        int temp;
        for (int i = (size - 1); i >= 0; i--) {
            for (int j = 1; j <= i; j++) {
                if (array[j - 1] > array[j]) {
                    temp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    sort s;
    for (int i = 0; i < s.size; i++) {
        cout << "Enter a number: ";
        cin >> s.arr[i];
    }
    cout << "\nUnsorted: ";
    s.display();
    s.bubbleSort(s.arr);
    cout << "\n  Sorted: ";
    s.display();
}