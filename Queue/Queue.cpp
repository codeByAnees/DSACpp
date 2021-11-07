#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Queue {
    public:
    int *que;
    int size;
    int front;
    int rear;

    Queue() {
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
        if (rear == size - 1) {
            return true;
        }
        else return false;
    }

    void enqueue(int x) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        que[rear] = x;
    }

    int dequeue() {
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

    void display() {
        if (isEmpty()) {
            cout << "\nEmpty!\n";
        }
        else {
            for (int i = front; i < size; i++) {
                cout << que[i] << " ";
            }
        }
    }
};


int main() {
    Queue q;
    int x, i;
    do {
        cout << "\nEnter 1 to enqueue \nEnter 2 to dequeue \nEnter 3 to display \nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                if (!q.isFull()) {
                    cout << "\nEnter value to enqueue: ";
                    cin >> i;
                    q.enqueue(i);
                }
                else {
                    cout << "\nNo space!" << endl;
                }
                break;
            case 2:
                if (!q.isEmpty()) 
                    cout << "\nThe dequeued value is " << q.dequeue() << endl;
                else
                    cout << "\nNo element to dequeue!" << endl;
                break;
            case 3:
                q.display();
                break;
        }
    } while (x != 0);
}