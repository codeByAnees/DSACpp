#include<iostream>
#include <cmath>
using namespace std;

class MinHeap {
    public:
    int *heap;
    int top;

    MinHeap() {
        heap = new int[8];
        top = -1;
    }

    void insert() {
        int val;
        cout << "Enter a value: ";
        cin >> val;
        heap[++top] = val;
        heaps();
    }

    void heaps() {
        int parent, i;
        i = top;
        parent = (i - 1) / 2;
        while (heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void deletion() {
        if (top <= 2) {
           cout << "\nDeleted value is: " << heap[0] << endl;
           top--; 
        }
        else {
            cout << "\nDeleted value is: " << heap[0] << endl;
            int parent, left, right, min, i;
            heap[0] = heap[top];
            top--;
            i = 0;
            parent = (i - 1) / 2;
            left = (2 * i) + 1;
            right = (2 * i) + 2;
            min = (heap[left] < heap[right])? left : right;
            while (heap[min] < heap[parent]) {
                swap(heap[min], heap[parent]);
                parent = min;
                left = (2 * parent) + 1;
                right = (2 * parent) + 2;
                min = (heap[left] < heap[right])? left : right;
            }
        }
    }

    void display() {
        cout << endl;
        for (int i = 0; i <= top; i++) {
            cout << heap[i] << " ";
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