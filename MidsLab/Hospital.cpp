//Muhammad Anees
//FA20-BCS-045

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct emergency {
    string name;
    string address;
    int age;
    int dis;
    emergency *forw = NULL;
};

emergency *head = NULL, *tail = NULL, *current = NULL;

struct doctor {
    string Dname;
    int Dage;
    int Dtype;
    doctor *next = NULL;
    emergency *patient = NULL;
};

doctor *start = NULL, *end = NULL;

void doubleEnded() {
    doctor *p = NULL;
    p = start;
    while (p -> Dtype != 1 && p != NULL) {
        p = p -> next;
    }
    if (p == NULL) {
        cout << "Doctor not found!";
    }
    else {
        int choice;
        cout << "Enter 1 to add at front \nEnter 2 to add at rear: ";
        cin >> choice;
        if (p -> patient == NULL) {
            current -> forw = NULL;
            p -> patient = current;
        }
        else {
            if (choice == 1) {
                current -> forw = p -> patient;
                p -> patient = current;
            }
            else {
                emergency *q = NULL;
                q = p -> patient;
                while (q -> forw != NULL) {
                    q = q -> forw;
                }
                q -> forw = current;
                current -> forw = NULL;
            }
        }
    }
}

void circular() {
    doctor *p = NULL;
    p = start;
    while (p -> Dtype != 2 && p != NULL) {
        p = p -> next;
    }
    if (p == NULL) {
        cout << "Doctor not found!";
    }
    else {
        if (p -> patient == NULL) {
            current -> forw = NULL;
            p -> patient = current;
        }
        else {
            emergency *q = NULL;
            q = p -> patient;
            while (q -> forw != NULL) {
                q = q -> forw;
            }
            q -> forw = current;
            current -> forw = NULL;
        }
    }
}

void priority() {
    doctor *p = NULL;
    p = start;
    while (p -> Dtype != 3 && p != NULL) {
        p = p -> next;
    }
    if (p != NULL) {
        emergency *a = NULL;
        a = p -> patient;
        if (a == NULL) {
            current -> forw = NULL;
            p -> patient = current;
        }
        else if (current -> age == a -> age) {
            current -> forw = a -> forw;
            a -> forw = current;
        }
        else if (current -> age > a -> age) {
            current -> forw = a;
            p -> patient = current;
        }
        else {
            emergency *q = NULL;
            while (a -> age > current -> age && a != NULL) {
                q = a;
                a = a -> forw;
            }
            if (a -> age == current -> age) {
                current -> forw = a -> forw;
                a -> forw = current;
            }
            else {
                current -> forw = a;
                q -> forw = current;
            }
        }
    }
    else {
        cout << "No doctor found!";
    }
}

void refering() {
    if (current -> dis == 1) {
        doubleEnded();
    }
    else if (current -> dis == 2) {
        circular();
    }
    else if (current -> dis == 3) {
        priority();
    }
    else {
        cout << "\nInvalid Input!\n";
    }
}

void enqueueP() {
    //emergency *current = NULL;
    current = new emergency;
    cout << "\nEnter patient name: ";
    cin >> current -> name;
    cout << "Enter patient age: ";
    cin >> current -> age;
    cout << "Enter address: ";
    cin >> current -> address;
    cout << endl;
    cout << "Enter 1 for ENT"
            "\nEnter 2 for skin infection"
            "\nEnter 3 for cardic problem: ";
    cin >> current -> dis;
    if (head == NULL) {
        head = tail = current;
    }
    else {
        tail -> forw = current;
        tail = current;
    }
    refering();
}

void dequeing() {
    int choice;
    cout << "\nEnter 1 for ENT"
            "\nEnter 2 for skin infection"
            "\nEnter 3 for cardic problem: ";
    cin >> choice;
    doctor *a = NULL;
    a = start;
    while (a -> Dtype != choice && a != NULL) {
        a = a -> next;
    }
    if (a -> Dtype == 1) {
        int choose;
        cout << "\nEnter 1 to exit from rear"
                "\nEnter 2 to exit from front: ";
        cin >> choose;
        if (choose == 1) {
            emergency *q = NULL;
            q = a -> patient;
            while (q -> forw -> forw != NULL) {
                q = q -> forw;
            }
            delete q -> forw;
            q -> forw = NULL;
        }
        else {
            emergency *n = NULL;
            n = a -> patient;
            a -> patient = n -> forw;
            delete n;
        }
    }
    else if (a -> Dtype == 2) {
        if (a -> patient == NULL) {
            cout << "\nNothing to check\n";
        }
        else {
            emergency *s = NULL;
            s = a -> patient;
            a -> patient = s -> forw;
            delete s;
        }
    }
    else {
        if (a -> patient == NULL) {
            cout << "Nothing to check";
        }
        else {
            emergency *x = NULL;
            x = a -> patient;
            a -> patient = x -> forw;
            delete x;
        }
    }
}

void doc() {
    doctor *cur = NULL;
    cur = new doctor;
    cout << "\nEnter doctor name: ";
    cin >> cur -> Dname;
    cout << "Enter doctor age: ";
    cin >> cur -> Dage;
    cout << "\n\tDoctor specialization?"
            "\nEnter 1 for ENT"
            "\nEnter 2 for Skin"
            "\nEnter 3 for Cardic: ";
    cin >> cur -> Dtype;
    if (start == NULL) {
        start = end = cur;
    }
    else {
        end -> next = cur;
        end = cur;
    }
}

void display() {
    doctor *p = NULL;
    p = start;
    while (p != NULL) {
        cout << "\n\t\tDoctor";
        cout << "\nDoctor name: " << p -> Dname << endl;
        cout << "Doctor age: " << p -> Dage << endl;
        switch (p -> Dtype) {
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
        emergency *q = NULL;
        q = p -> patient;
        while (q != NULL) {
            cout << "\n\tPatinet Details\n";
            cout << "Name: " << q -> name << endl;
            cout << "Age: " << q -> age << endl;
            cout << "Address: " << q -> address << endl;
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
            doc();
            break;
        case 2:
            enqueueP();
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
