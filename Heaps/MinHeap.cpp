#include<iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

class MinHeap {
    public:
    int *arr;
    int top;

    MinHeap() {
        arr = new int[8];
        top = -1;
    }

    void insert() {
        int val;
        cout << "Enter a value: ";
        cin >> val;
        arr[++top] = val;
    }

    void heap() {
        int parent, i;
        i = top;
        parent = (i - 1) / 2;
        while (arr[i] < arr[parent] && i >= 0 && parent >= 0) {
            int temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void deletion() {
        if (top <= 2) {
           cout << "\nDeleted value is: " << arr[0] << endl;
           top--; 
        }
        else {
            cout << "\nDeleted value is: " << arr[0] << endl;
            int parent, left, right, min, i;
            arr[0] = arr[top];
            top--;
            i = 0;
            parent = (i - 1) / 2;
            left = (2 * i) + 1;
            right = (2 * i) + 2;
            min = (arr[left] < arr[right])? left : right;
            while (arr[min] < arr[parent] && min >= 0 && parent >= 0) {
                int temp = arr[parent];
                arr[parent] = arr[min];
                arr[min] = temp;
                parent = min;
                left = (2 * parent) + 1;
                right = (2 * parent) + 2;
                min = (arr[left] < arr[right])? left : right;
            }
        }
    }

    void display() {
        cout << endl;
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    MinHeap m;
    int x;
    do {
        cout << "\nEnter 1 to insert \nEnter 2 to delete \nEnter 3 to display \nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                m.insert();
                m.heap();
                break;
            case 2:
                m.deletion();
                break;
            case 3:
                m.display();
                break;
        }
    } while (x != 0);
}