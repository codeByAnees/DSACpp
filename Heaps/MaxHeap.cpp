#include<iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

class MaxHeap {
    public:
    int *heap;
    int top;
    MaxHeap() {
        heap = new int[8];
        top = -1;
    }

    void insert() {
        int val;
        cout << "Enter a value: ";
        cin >> val;
        heap[++top] = val;
    }

    void heap() {
        int parent, i;
        i = top;
        parent = (i - 1) / 2;
        while (heap[i] > heap[parent] && i >= 0 && parent >= 0) {
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
            int parent, left, right, max, i, temp;
            heap[0] = heap[top];
            top--;
            i = 0;
            parent = (i - 1) / 2;
            left = (2 * i) + 1;
            right = (2 * i) + 2;
            max = (heap[left] > heap[right])? left : right;
            while (heap[max] > heap[parent]) {
                swap(heap[max], heap[parent]);
                parent = max;
                left = (2 * parent) + 1;
                right = (2 * parent) + 2;
                max = (heap[left] > heap[right])? left : right;
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
    MaxHeap m;
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