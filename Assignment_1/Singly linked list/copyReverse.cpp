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

void copyReverse(node *st) {
    node *p = st, *q = end, *k = st;
    if (p != NULL) {
        while (p != q) {
            if (p -> next == q) {
                string a = p -> id;
                p -> id = q -> id;
                q -> id = a;
                break;
            }
            else {
                while (p -> next != q) {
                    p = p -> next;
                }
                string a = p -> next -> id;
                p -> next -> id = k -> id;
                k -> id = a;
                q = p;
                k = k -> next;
                p = k;
            }
        }
        cout << "\nSuccessful!\n";
    }
    else cout << "\nNothing to reverse!\n";
}


int main() {
    int opt;
    do {
        cout << "\nEnter 1 to INSERT \nEnter 2 to Copy Reverse"
        "\nEnter 3 to DISPLAY \nEnter 0 to QUIT--> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                insertAtEnd();
                break;
            case 2:
                copyReverse(start);
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