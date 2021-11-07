#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct node {
    int id;
    node *next = NULL;
};

node *front = NULL, *rear = NULL, *current = NULL;

bool isEmpty() {
    if (front == NULL) {
        return true;
    }
    else return false;
}

void enqueue() {
    current = new node;
    cout << "\nEnter value: ";
    cin >> current -> id;
    if (front == NULL) {
        front = rear = current;
    }
    else {
        rear -> next = current;
        rear = current;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "\nEmpty\n";
    }
    else {
        if (front == rear) {
            cout << "\nThe dequeued value is " << front -> id << endl;
            delete front;
            front = rear = NULL;
        }
        else {
            node *a = front;
            front = a -> next;
            cout << "\nThe dequeued value is " << a -> id << endl;
            delete a;
        }
    }
}

void display() {
    if (isEmpty()) {
        cout << "\nEmpty\n";
    }
    else {
        node *p = front;
        while (p != NULL) {
            cout << p -> id << " ";
            p = p -> next;
        }
    }
}

int main() {
    int x;
    do {
        cout << "\nEnter 1 to enqueue \nEnter 2 to dequeue" 
                "\nEnter 3 to display \nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    } while (x != 0);
}