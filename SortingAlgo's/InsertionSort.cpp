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

    void insertionSort(int array[]) {
        int j, temp;
        for (int i = 1; i < size; i++) {
            temp = array[i];
            j = i;
            while ((j > 0) && (temp < array[j - 1])) {
                array[j] = array[j - 1];
                j = j - 1;
            }	
            array[j] = temp;
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
    s.insertionSort(s.arr);
    cout << "\n  Sorted: ";
    s.display();
}
