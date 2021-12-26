#include<iostream>
using namespace std;

class search {
    public:
    int *arr;
    int size;

    search() {
        int x;
        cout << "Enter length of list: ";
        cin >> x;
        size = x;
        arr = new int[size];
    }

    int binarySearch(int array[], int size, int key) {
        static int start = 0, end = size - 1, mid = (start + end) / 2;
        if (start == end) {
            return mid;
        }
        else if (array[mid] == key) {    
            return mid;
        }
        else if (array[mid] < key) {
            start = mid + 1;
            end = size - 1;
            mid = (start + end) / 2;
            return binarySearch(array, (start + end), key);
        }
        else if (array[mid] > key) {
            start = 0;
            end = mid - 1;
            mid = (start + end) / 2;
            return binarySearch(array, (start + end), key);
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    search s;
    for (int i = 0; i < s.size; i++) {
        cout << "Enter a number: ";
        cin >> s.arr[i];
    }
    s.display();
    int key;
    cout << "\nEnter a value to search: ";
    cin >> key;
    int ans = s.binarySearch(s.arr, s.size, key);
    if (s.arr[ans] == key) {
        cout << "Value found";
    }
    else cout << "Value not found";
}

