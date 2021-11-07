#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct node {
    int priority;
    string name;
    float age;
    string address;
    node *next = NULL;
};

node *head = NULL, *tail = NULL, *current = NULL;

// Madical Emergency Priority order
// 1) LIFE THREATNING INJURY
// 2) Chest pain and shortness of breath
// 3) Physical pain
// 4) Fever, flu or cough

int priority(int opt) {
    switch (opt) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    default:
        break;
    }
}

void push() {
    current = new node;
    cout << "\n\t\tEnter Patient Details" << endl;
    cout << "Enter name: ";
    cin >> current -> name;
    cout << "Enter age: ";
    cin >> current -> age;
    cout << "Enter address: ";
    cin >> current -> address;
    int opt, pri;
    cout << "Enter 1 for fever or cough"
            "\nEnter 2 for any physical pain"
            "\nEnter 3 for chest pain and breath shortness"
            "\nEnter 4 for LIFE THREATNING INJURY: ";

    cin >> opt;
    pri = priority(opt);
    current -> priority = pri;
    if (head == NULL) {
        head = tail = current;
    }
    else if (current -> priority == head -> priority) {
        current -> next = head -> next;
        head -> next = current;
    }
    else if (current -> priority > head -> priority) {
        current -> next = head;
        head = current;
    }
    else if (current -> priority < tail -> priority) {
        tail -> next = current;
        tail = current;
    }
    else {
        node *p = head, *q = NULL;
        while (p -> priority > current -> priority && p != NULL) {
            q = p;
            p = p -> next;
        }
        if (p -> priority == current -> priority) {
            current -> next = p -> next;
            p -> next = current;
        }
        else {
            current -> next = p;
            q -> next = current;
        }
    }
    cout << "\nSuccessful.\n";
}


void pop() {
    if (head == NULL) {
        cout << "\nNo patient!" << endl;
    }
    else {
        node *a = head;
        head = a -> next;
        cout << "\n\t\tPatient Details" << endl;
        cout << "Patient name: " << a -> name << endl;
        cout << "Patient age: " << a -> age << endl;
        cout << "Address: " << a -> address << endl;
        cout << "Medical Emergency: ";
        if (a -> priority == 4) {
            cout << "Life threatning injury." << endl;
        }
        else if (a -> priority == 3) {
            cout << "Chest pain and shortness of breath." << endl;
        }
        else if (a -> priority == 2) {
            cout << "Physical pain." << endl;
        }
        else cout << "Fever, flue or cough." << endl;
        delete a;
    }
}

void display() {
    node *a = head;
    if (a == NULL) {
        cout << "\nNo record found!" << endl;
    }
    else {
        while (a != NULL) {
            cout << "\n\t\tPatient Details" << endl;
            cout << "Patient name: " << a -> name << endl;
            cout << "Patient age: " << a -> age << endl;
            cout << "Address: " << a -> address << endl;
            cout << "Medical Emergency: ";
            if (a -> priority == 4) {
                cout << "Life threatning injury." << endl;
            }
            else if (a -> priority == 3) {
                cout << "Chest pain and shortness of breath." << endl;
            }
            else if (a -> priority == 2) {
                cout << "Physical pain." << endl;
            }
            else cout << "Fever, flue or cough." << endl;
            a = a -> next;
        }
    }
}

int main() {
    int x;
    do {
        cout << "\nEnter 1 to enqueue a patient \nEnter 2 to dequeue a patient" 
        "\nEnter 3 to display all patients \nEnter 0 to QUIT --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    } while (x != 0);
}