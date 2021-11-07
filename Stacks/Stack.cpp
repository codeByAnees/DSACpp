#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class stack {
    public:
    int *arr;
    int size;
    int top;

    stack() {
        int x;
        cout << "Enter length of stack: ";
        cin >> x;
        size = x;
        arr = new int[size];
        top = -1;
    }

    stack(int s) {
        size = s;
        top = -1;
        arr = new int[s];
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else return false;
    }

    bool isFull() {
        if (top == size - 1) {
            return true;
        }
        else return false;
    }

    void push(int a) {
        arr[++top] = a;
    }

    int pop() {
        int x;
        if (!isEmpty()) {
            x = arr[top--];
            return x;
        }
        else {
            cout << "\nNo element to remove!" << endl;
        }
    }

    void display() {
        if (!isEmpty()) {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
        }
        else {
            cout << "\nStack is empty!" << endl;
        }
    }
};

int main() {
    stack s1;
    int x, i;
    do {
        cout << "\nEnter 1 to push \nEnter 2 to pop \nEnter 3 to display \nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                if (!s1.isFull()) {
                    cout << "\nEnter value to push: ";
                    cin >> i;
                    s1.push(i);
                }
                else {
                    cout << "\nNo space!" << endl;
                }
                break;
            case 2:
                if (!s1.isEmpty()) 
                    cout << "\nThe popped value is " << s1.pop() << endl;
                else
                    cout << "\nNo element to remove!" << endl;
                break;
            case 3:
                s1.display();
                break;
        }
    } while (x != 0);
}