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

    void selectionSort(int array[]) {
        int small, temp;
        for (int i = 0; i < size - 1; i++)	{
            small = i;
            for (int j = i + 1; j < size; j++) {
                if (array[j] < array[small]) {
                    small = j;
                }
            }
            if (small != i) {
                temp = array[small];
                array[small] = array[i];
                array[i] = temp;
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
    s.selectionSort(s.arr);
    cout << "\n  Sorted: ";
    s.display();
}