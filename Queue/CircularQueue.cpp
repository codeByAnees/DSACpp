#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class CircularQue {
    public:
    int *que;
    int size;
    int front;
    int rear;

    CircularQue() {
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
        if ((rear + 1) % size == front) {
            return true;
        }
        else return false;
    }

    void enqueue(int x) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = ((rear + 1) % size);
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
                front = ((front + 1) % size);
            }
        }
        return x;
    }

    void display() {
        if (front == -1) {
            cout << "\nEmpty\n";
        }
        else {
            for (int i = front; i < size; i++) {
                cout << que[(i + 1) % size] << " ";
            }
        }
    }
};

int main() {
    CircularQue q;
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