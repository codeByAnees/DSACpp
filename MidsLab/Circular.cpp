#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct emergency {
    string name;
    int age;
    int dis;
    emergency *forw = NULL;
};

struct doctor {
    string dName;
    int dAge;
    int dType;
    doctor *next = NULL;
    emergency *patient = NULL;
};

doctor *head = NULL, *tail = NULL, *current = NULL;

void addDoctor() {
    current = new doctor;
    cout << "\n\t\tDoctor\n";
    cout << "Enter name: ";
    cin >> current -> dName;
    cout << "Enter age: ";
    cin >> current -> dAge;
    cout << "\n\tDoctor specialization?"
            "\nEnter 1 for ENT"
            "\nEnter 2 for Skin"
            "\nEnter 3 for Cardic: ";
    cin >> current -> dType;
    if (head == NULL) {
        head = tail = current;
    }
    else {
        tail -> next = current;
        tail = current;
    }
    cout << "\nSuccessful\n";
}

void addPatient() {
    int choice;
    cout << "\nEnter 1 for ENT"
            "\nEnter 2 for Skin"
            "\nEnter 3 for Cardic: ";
    cin >> choice;
    doctor *p = head;
    while (p -> dType != choice && p != NULL) {
        p = p -> next;
    }
    if (p -> dType == choice) {
        emergency *cur = new emergency;
        cur -> dis = choice;
        cout << "\n\t\tPatient\n";
        cout << "Enter name: ";
        cin >> cur -> name;
        cout << "Enter age: ";
        cin >> cur -> age;
        if (p -> patient == NULL) {
            p -> patient = cur;
        }
        else {
            emergency *a = p -> patient;
            while (a -> forw != NULL) {
                a = a -> forw;
            }
            a -> forw = cur;
        }
        cout << "\nSuccessful\n";
    }
    else {
        cout << "\nInvalid choice\n";
    }
}

void dequeing() {
    int choice;
    cout << "\nEnter 1 for ENT"
            "\nEnter 2 for Skin"
            "\nEnter 3 for Cardic: ";
    cin >> choice;
    doctor *p = head;
    while (p -> dType != choice) {
        p = p -> next;
    }
    if (p -> dType == choice) {
        if (p -> patient == NULL) {
            cout << "\nNothing to delete\n";
        }
        else {
            if (p -> patient -> forw == NULL) {
                delete p -> patient;
                p -> patient = NULL;
            }
            else {
                emergency *a = p -> patient;
                p -> patient = a -> forw;
                delete a;
            }
        }
        cout << "\nSuccessful\n";
    }
    else cout << "\nInvalid choice\n";
}

void display() {
    doctor *p = head;
    while (p != NULL) {
        cout << "\n\t\tDoctor\n";
        cout << "Name: " << p -> dName << endl;
        cout << "Age: " << p -> dAge << endl;
        switch (p -> dType) {
        case 1:
            cout << "Specialist in ENT" << endl;
            break;
        case 2:
            cout << "Specialist in Skin" << endl;
            break;
        case 3:
            cout << "Specialist in Cardic" << endl;
            break;
        }
        emergency *q = p -> patient;
        while (q != NULL) {
            cout << "\n\tPatient\n";
            cout << "Name: " << q -> name << endl;
            cout << "Age: " << q -> age << endl;
            q = q -> forw;
        }
        p = p -> next;
    }
}

int main() {
    int opt;
    do {
        cout << "\n\t\tHOSPITAL MANAGEMENT SYSTEM\n";
        cout << "\nEnter 1 to add new Doctor \nEnter 2 to add a patient"
                "\nEnter 3 to remove a patient"
                "\nEnter 4 to display all details"
                "\nEnter 0 to QUIT ---> ";
        cin >> opt;
        switch (opt) {
        case 0:
            break;
        case 1:
            addDoctor();
            break;
        case 2:
            addPatient();
            break;
        case 3:
            dequeing();
            break;
        case 4:
            display();
            break;
        default:
            cout << "\nYou selected invalid option!";
            break;
        }
    } while (opt != 0);
    return 0;
}