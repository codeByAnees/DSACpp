#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class DEQ {
    public:
    int *que;
    int size;
    int front;
    int rear;

    DEQ() {
        cout << "Enter length of Queue: ";
        cin >> size;
        que = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        else return false;
    }

    bool isFull() {
        if (front == 0 && rear == size - 1) {
            return true;
        }
        else return false;
    }

    void addToFront(int x) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front != 0) {
            front--;
        }
        else {
            rear++;
            for (int i = rear; i >= front; i--) {
                que[i] = que[i - 1];
            }
        }
        que[front] = x;
        
    }

    void addToLast(int x) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1) {
            front--;
            for (int i = front; i <= rear; i++) {
                que[i] = que[i + 1];
            }
        }
        else {
            rear++;
        }
        que[rear] = x;
    }

    int removeFront() {
        int x;
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            x = que[front];
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
        }
        return x;
    }

    int removeLast() {
        int x;
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            x = que[rear];
            if (front == rear) {
                front = rear = -1;
            }
            else {
                rear--;
            }
        }
        return x;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << que[i] << " ";
            }
        }
    }
};

int main() {
    DEQ q;
    int x, i;
    do {
        cout << "\nEnter 1 to Add to front \nEnter 2 to Add at end" 
                "\nEnter 3 to remove first \nEnter 4 to remove last" 
                "\nEnter 5 to display \nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                if (!q.isFull()) {
                    cout << "\nEnter value at front: ";
                    cin >> i;
                    q.addToFront(i);
                }
                else {
                    cout << "\nNo space!" << endl;
                }
                break;
            case 2:
                if (!q.isFull()) {
                    cout << "\nEnter value at end: ";
                    cin >> i;
                    q.addToLast(i);
                }
                else {
                    cout << "\nNo space!" << endl;
                }
                break;
            case 3:
                if (!q.isEmpty()) 
                    cout << "\nThe first value is " << q.removeFront() << endl;
                else
                    cout << "\nNo element to remove!" << endl;
                break;
            case 4:
                if (!q.isEmpty()) 
                    cout << "\nThe last value is " << q.removeLast() << endl;
                else
                    cout << "\nNo element to remove!" << endl;
                break;
            case 5:
                q.display();
                break;
        }
    } while (x != 0);
}