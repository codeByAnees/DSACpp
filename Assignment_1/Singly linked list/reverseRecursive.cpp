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

void display(node *p){
    if (p != NULL) {
        display(p -> forward);
        cout << p -> id << " ";
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
                display(start);
                break;
            default:
                cout << "\nYou selected invalid option!";
                break;
            } 
    } while (opt != 0);
        return 0;
}