#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct node {
    int id;
    node *next = NULL, *prev = NULL;
};

node *start1 = NULL, *end1 = NULL, *current = NULL;
node *start2 = NULL, *end2 = NULL;

void insert_1st() {
    current = new node;
    cout << "Enter value for list1: ";
    cin >> current -> id;

    if (start1 == NULL) {
        start1 = end1 = current;
    }
    else {
        end1 -> next = current;
        current -> prev = end1;
        end1 = current;
    }
}

void insert_2nd() {
    current = new node;
    cout << "Enter value for list2: ";
    cin >> current -> id;

    if (start2 == NULL) {
        start2 = end2 = current;
    }
    else {
        end2 -> next = current;
        current -> prev = end2;
        end2 = current;
    }
}

node *intersection(node *st1, node *st2) {
    node *newStart = NULL, *newEnd = NULL;
    node *p = st1, *q = st2, *k = st2;
    while (p != NULL) {
        while (p -> id != q -> id && q -> next != NULL) {
            q = q -> next;
        }
        if (p -> id == q -> id) {
            if (newStart == NULL) {
                current = new node;
                current -> id = p -> id;
                newStart = newEnd = current;
                p = p -> next;
                q = k;
            }
            else {
                current = new node;
                current -> id = p -> id;
                newEnd -> next = current;
                current -> prev = newEnd;
                newEnd = current;
                p = p -> next;
                q = k;
            }
        }
        else {
            p = p -> next;
            q = k;
        }
    }
    return newStart;
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
        insert_1st();
    }
    cout << endl;
    for (int i = 0; i < x; i++) {
        insert_2nd();
    }

    cout << "List 1 --> ";
    displayingList(start1);
    cout << "List 2 --> ";
    displayingList(start2);

    node *m = intersection(start1, start2);
    if (m == NULL) {
        cout << "\tNothing Common!";
    }
    else {
        cout << "Common --> ";
        while (m != NULL) {
            cout << m -> id << " ";
            m = m -> next;
        }
    }
}