#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct node {
    int id;
    node *next = NULL;
};

node *start = NULL, *end = NULL, *current = NULL;

void insertAtEnd() {
    current = new node;
    cout << "Enter value: ";
    cin >> current -> id;

    if (start == NULL) {
        start = end = current;
    }
    else {
        end -> next = current;
        end = current;
    }
}


void sortedInsertion() {
    current = new node;
    cout << "\nEnter new value: ";
    cin >> current -> id;
    if (current -> id < start -> id) {
        current -> next = start;
        start = current;
    }
    else {
        node *p = start, *q = NULL;
        while (p -> id < current -> id && p -> next != NULL) {
            q = p;
            p = p -> next;
        }
        if (p -> next == NULL && current -> id > p -> id) {
            p -> next = current;
            end = current;
        }
        else {
            current -> next = p;
            q -> next = current;
        }
    }
}

void display() {
    node *p;
    if (start == NULL) {
        cout << "\nNo value to display\n";
    }
    else {
        p = start;
        while (p != NULL) {
            cout << p -> id << " ";
            p = p -> next;
        }
    }
}


int main() {
    for (int i = 0; i < 5; i++) {
        insertAtEnd();
    }
    display();
    sortedInsertion();
    display();
}