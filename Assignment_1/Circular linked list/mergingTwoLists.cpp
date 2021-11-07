#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct node {
    int id;
    node *next = NULL;
};

node *head = NULL, *tail = NULL;

node *start1 = NULL, *end1 = NULL, *current = NULL;

node *start2 = NULL, *end2 = NULL;

void insertAtEnd_1() {
    current = new node;
    cout << "Enter value for list1: ";
    cin >> current -> id;

    if (start1 == NULL) {
        start1 = current;
        end1 = current;
    }
    else {
        end1 -> next = current;
        end1 = current;
    }
}

void insertAtEnd_2() {
    current = new node;
    cout << "Enter value for list2: ";
    cin >> current -> id;

    if (start2 == NULL) {
        start2 = current;
        end2 = current;
    }
    else {
        end2 -> next = current;
        end2 = current;
    }
}


void sorting(node *st) {
    node *p = st;
    while (p != NULL) {
        current = new node;
        current -> id = p -> id;
        if (head == NULL) {
            head = current;
            tail = current;
            p = p -> next;
        }
        else if (current -> id > head -> id) {
            current -> next = head;
            head = current;
            p = p -> next;
        }
        else if (current -> id < tail -> id) {
            tail -> next = current;
            tail = current;
            p = p -> next;
        }
        else {
            node *k = head, *q = NULL;
            while (k -> id > current -> id && k != NULL) {
                q = k;
                k = k -> next;
            }
            current -> next = k;
            q -> next = current;
            p = p -> next;
        }
    }
}

void display() {
    node *p = start1, *q = head;
    while (p != NULL) {
        cout << p -> id << " ";
        while (q != NULL) {
            cout << q -> id << " ";
            break;
        }
        p = p -> next;
        q = q -> next;
    }
}

void displayingList(node *a) {
    node *p = a;
    while (p != NULL) {
        cout << p -> id << " ";
        p = p -> next;
    }
    cout << endl;
}

int main() {
    int x;
    cout << "\n\t\tEnter LENGTH of lists -> ";
    cin >> x;
    cout << endl;

    for (int i = 0; i < x; i++) {
        insertAtEnd_1();
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
        insertAtEnd_2();
    }
    cout << "List 1 --> ";
    displayingList(start1);
    cout << "List 2 --> ";
    displayingList(start2);

    sorting(start1);
    node *a = start1, *b = head;
    while (a != NULL) {
        a -> id = b -> id;
        a = a -> next;
        b = b -> next;
    }
    head = tail = NULL;
    sorting(start2);
    cout << "Output --> ";
    display();
}

