#include<iostream>
using std::cin;
using std::cout;

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


node *search(int key) {
    node *p = start;
    if (p -> id == key) {
        return p;
    }
    else {
        while (p -> next -> id != key && p -> next != NULL) {
            p = p -> next;
            if (p -> next == NULL) {
                return NULL;
                break;
            }
        }
        return p;
    }
}


void swap(int num1, int num2) {
    node *p = search(num1);
    node *q = search(num2);
    if (start != NULL) {
        if (p == NULL || q == NULL) {
            cout << "\nKey not found!\n";
        }
        else if (p == q) {
            q = q -> next;
            node *n = q -> next;
            q -> next = p;
            p -> next = n;
            start = q;
        }
        else if (p == start && p -> next -> id == num1) {
            node *n = p -> next -> next;
            node *s = q -> next -> next, *k = q -> next;
            q -> next -> next = n;
            q -> next = p -> next;
            p -> next -> next = s;
            p -> next = k;
        }
        else if (q == start && q -> next -> id == num2) {
            node *n = q -> next -> next;
            node *s = p -> next -> next, *k = p -> next;
            p -> next -> next = n;
            p -> next = q -> next;
            q -> next -> next = s;
            q -> next = k;
        }
        else {
            if (p == start && q -> next == end) {
                start = q -> next;
                q -> next -> next = p -> next;
                q -> next = p;
                p -> next = NULL;
                end = p;
            }
            else if (q == start && p -> next == end) {
                start = p -> next;
                p -> next -> next = q -> next;
                p -> next = q;
                q -> next = NULL;
                end = q;
            }
            else if (p == start && q -> next != end) {
                node *k = NULL;
                k = q -> next -> next;
                start = q -> next;
                q -> next -> next = p -> next;
                q -> next = p;
                p -> next = k;
            }
            else if (q == start && p -> next != end) {
                node *k = NULL;
                k = p -> next -> next;
                start = p -> next;
                p -> next -> next = q -> next;
                p -> next = q;
                q -> next = k;
            }
            else if (p -> next == end && q -> next == p) {
                q -> next = p -> next;
                q -> next -> next = p;
                p -> next = NULL;
                end = p;
            }
            else if (q -> next == end && p -> next == q) {
                p -> next = q -> next;
                p -> next -> next = q;
                q -> next = NULL;
                end = q;
            }
            else if (p -> next == end && q -> next != p) {
                node *k = q -> next;
                p -> next -> next = q -> next -> next;
                q -> next = p -> next;
                p -> next = k;
                k -> next = NULL;
                end = k;
            }
            else if (q -> next == end && p -> next != q) {
                node *k = p -> next;
                q -> next -> next = p -> next -> next;
                p -> next = q -> next;
                q -> next = k;
                k -> next = NULL;
                end = k;
            }
            else if (p -> next == q) {
                node *n = q -> next -> next;
                q -> next -> next = p -> next;
                p -> next = q -> next;
                q -> next = n;
            }
            else if (q -> next == p) {
                node *n = p -> next -> next;
                p -> next -> next = q -> next;
                q -> next = p -> next;
                p -> next = n;
            }
            else {
                node *k = p -> next;
                node *n = q -> next -> next;
                p -> next = q -> next;
                q -> next -> next = k -> next;
                q -> next = k;
                k -> next = n;
            }
        }
    }
    else {
        cout << "\nList is EMPTY!\n";
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
    int a;
    cout << "\n\t\tEnter length of list -> ";
    cin >> a;

    for (int i = 0; i < a; i++) {
        insertAtEnd();
    }
    display();
    int x,y;
    cout << "\nEnter number to swap: ";
    cin >> x;
    cout << "Enter number to swap: ";
    cin >> y;
    swap(x,y);
    display();
}