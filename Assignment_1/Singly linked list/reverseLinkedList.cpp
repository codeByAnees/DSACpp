#include<iostream>
using std::cin;
using std::cout;
using std::string;

struct node {
    string id;
    node *next = NULL;
};

node *start = NULL, *end = NULL, *current = NULL;

void insertAtEnd() {
    current = new node;
    cout << "Enter string value: ";
    cin >> current -> id;

    if (start == NULL) {
        start = end = current;
    }
    else {
        end -> next = current;
        end = current;
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


void reverseLinkedList(node *st) {
    node *p = st, *q = end, *k = st, *n = NULL;
    if (p != NULL) {
        while (k -> next != q) {
            while (p -> next != q) {
                p = p -> next;
            }
            if (p -> next -> next == NULL) {
                start = p -> next;
                p -> next -> next = k -> next;
                p -> next = k;
                k -> next = NULL;
                end = k;
                q = p;
                p = k = start;
            }
            else {
                if (k -> next -> next == q) {
                    node *a = q -> next;
                    n = k -> next;
                    k -> next = q;
                    q -> next = n;
                    n -> next = a;
                }
                else { 
                    node *a = q -> next;
                    n = p -> next;
                    p -> next -> next = k -> next -> next;
                    p -> next = k -> next;
                    p -> next -> next = a;
                    k -> next = q;
                    q = p;
                    p = k = n;
                }
            }        
        }
        cout << "\nSuccessful!\n";
    }
    else cout << "\nNothing to reverse!\n";
}


int main() {
    int opt;
    do {
        cout << "\nEnter 1 to INSERT \nEnter 2 to Reverse Linked List"
        "\nEnter 3 to Display \nEnter 0 to QUIT--> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                insertAtEnd();
                break;
            case 2:
                reverseLinkedList(start);
                break;
            case 3:
                display();
                break;
            default:
                cout << "\nYou selected invalid option!";
                break;
            } 
    } while (opt != 0);
        return 0;
}


