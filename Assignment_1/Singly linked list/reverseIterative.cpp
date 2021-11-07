#include<iostream>
using std::cin;
using std::cout;

struct node {
    int id;
    node *forward = NULL;
};

node *start = NULL, *end = NULL, *temp = NULL;

void insertAtEnd() {
    temp = new node;
    cout << "Enter value: ";
    cin >> temp -> id;

    if (start == NULL) {
        start = temp;
        end = temp;
    }
    else {
        end -> forward = temp;
        end = temp;
    }
}

void display() {
    if (start == NULL) {
        cout << "\nNo value to display\n";
    }
    else {
        node *k = end;
        while (k != start) {
            node *p = start;
            while (p -> forward != k) {
                p = p -> forward;
            }
            cout << k -> id << " ";
            k = p;
        }
        cout << k -> id << " ";
    }
}


int main() {
    int opt;
    do {
        cout << "\nEnter 1 to INSERT \nEnter 2 to Reverse Display"
        "\nEnter 0 to QUIT--> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                insertAtEnd();
                break;
            case 2:
                display();
                break;
            default:
                cout << "\nYou selected invalid option!";
                break;
            } 
    } while (opt != 0);
        return 0;
}