#include<iostream>
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

emergency *start = NULL, *end = NULL;

struct doctor {
    string dName;
    string dAddress;
    int dAge;
    int dType;
    doctor *next = NULL;
    emergency *patient = NULL;
};

doctor *head = NULL, *tail = NULL, *current = NULL;

void addDoctor() {
    current = new doctor;
    cout << "\n\t\tEnter Doctor Details\n";
    cout << "Enter name of doctor: ";
    cin >> current -> dName;
    cout << "Enter age of doctor: ";
    cin >> current -> dAge;
    cout << "Enter address of doctor: ";
    cin >> current -> dAddress;
    cout << "\nDoctor's specialization?"
            "\nEnter 1 for Ear, nose and throat"
            "\nEnter 2 for Skin or"
            "\nEnter 3 for Cardic: ";
    cin >> current -> dType;
    if (head == NULL) {
        head = tail = current;
    }
    else {
        tail -> next = current;
        tail = current;
    }
    cout << "\nSuccessful!\n";
}

void doubleEnded() {
    int choice = 1;
    doctor *p = head;
    while (p -> dType != choice && p != NULL) {
        p = p -> next;
    }
    emergency *cur = start;
    cur -> forw = NULL;
    int opt;
    cout << "Enter 1 to add patient at front \nEnter 2 to add patient at rear: ";
    cin >> opt;
    if (p -> patient == NULL) {
        p -> patient = cur;
    }
    else {
        if (opt == 1) {
            cur -> forw = p -> patient;
            p -> patient = cur;
        }
        else {
            emergency *a = p -> patient;
            while (a -> forw != NULL) {
                a = a -> forw;
            }
            a -> forw = cur;
        }
    }
    cout << "\nSuccessful!\n";
}

void circular() {
    int choice = 2;
    doctor *p = head;
    while (p -> dType != choice && p != NULL) {
        p = p -> next;
    }
    emergency *cur = start;
    cur -> forw = NULL;
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

void priority() {
    int choice = 3;
    doctor *p = head;
    while (p -> dType != choice && p != NULL) {
        p = p -> next;
    }
    emergency *b = p -> patient;
    emergency *cur = start;
    cur -> forw = NULL;
    if (p -> patient == NULL) {
        p -> patient = cur;
    }
    else if (b -> age == cur -> age) {
        cur -> forw = b -> forw;
        b -> forw = cur;
    }
    else if (cur -> age > b -> age) {
        cur -> forw = b;
        p -> patient = cur;
    }
    else {
        emergency *q = NULL;
        while (b -> age > cur -> age && b != NULL) {
            q = b;
            b = b -> forw;
        }
        if (b -> age == cur -> age) {
            cur -> forw = b -> forw;
            b -> forw = cur;
        }
        else {
            cur -> forw = b;
            q -> forw = cur;
        }
    }
    cout << "\nSuccessful!\n";
}


void addPatient() {
    if (head != NULL) {
        int choice;
        cout << "\nEnter 1 for Ear, nose or throat"
                "\nEnter 2 for Skin problems"
                "\nEnter 3 for Cardic issues: ";
        cin >> choice;
        doctor *a = head;
        while (a -> dType != choice && a -> next != NULL) {
            a = a -> next;
        }
        if (a -> dType == choice) {
            emergency *cur = new emergency;
            cur -> dis = choice;
            cout << "\n\t\tEnter Patient Details\n";
            cout << "Enter name of patient: ";
            cin >> cur -> name;
            cout << "Enter age of patient: ";
            cin >> cur -> age;
            cout << "Enter address of patient: ";
            cin >> cur -> address;
            if (start == NULL) {
                start = end = cur;
            }
            else {
                cur -> forw = start;
                start = cur;
            }
            if (choice == 1) {
                doubleEnded();
            }
            else if (choice == 2) {
                circular();
            }
            else if (choice == 3) {
                priority();
            }
            else {
                cout << "\nInvalid choice!\n";
            }
        }
        else {
            cout << "\nSorry, Doctor for this disease is not available!\n";
        }
    }
    else cout << "\nNo doctor available!\n";
}

void dequeDoubleEnded() {
    int choice = 1;
    doctor *p = head;
    while (p -> dType != choice) {
        p = p -> next;
    }
    if (p -> dType == choice) {
        if (p -> patient == NULL) {
            cout << "\nNo Patient!\n";
        }
        else {
            if (p -> patient -> forw == NULL) {
                delete p -> patient;
                p -> patient = NULL;
            }
            else {
                int opt;
                cout << "\nEnter 1 to exit from front \nEnter 2 to exit from rear: ";
                cin >> opt;
                if (opt == 1) {
                    emergency *a = p -> patient;
                    p -> patient = a -> forw;
                    delete a;
                }
                else {
                    emergency *b = p -> patient;
                    while (b -> forw -> forw != NULL) {
                        b = b -> forw;
                    }
                    delete b -> forw;
                    b -> forw = NULL;
                }
            }
            cout << "\nSuccessful!\n";
        }
    }
    else cout << "\nInvalid choice!\n";
}

void dequeue(int opt) {
    int choice = opt;
    doctor *p = head;
    while (p -> dType != choice) {
        p = p -> next;
    }
    if (p -> dType == choice) {
        if (p -> patient == NULL) {
            cout << "\nNo patient!\n";
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
            cout << "\nSuccessful!\n";
        }
    }
    else cout << "\nInvalid choice!\n";
}

void dequeing() {
    if (head != NULL && start != NULL) {
        int choice;
        cout << "\nEnter 1 for Ear, nose or throat"
                "\nEnter 2 for Skin problems"
                "\nEnter 3 for Cardic issues: ";
        cin >> choice;
        if (choice == 1) {
            dequeDoubleEnded();
        }
        else if (choice == 2 || choice == 3) {
            if (choice == 2) {
                dequeue(2);
            }
            else {
                dequeue(3);
            }
        }
        else {
            cout << "\nInvalid choice!\n";
        }
    }
    else cout << "\nNo patient!\n";
}

void display() {
    if (head != NULL) {
        doctor *p = head;
        while (p != NULL) {
            cout << "\n\t\tDOCTOR\n";
            cout << "Doctor name: " << p -> dName << endl;
            cout << "Doctor age: " << p -> dAge << endl;
            cout << "Doctor's address: " << p -> dAddress << endl;
            switch (p -> dType) {
            case 1:
                cout << "Ear, nose and throat specialist." << endl;
                break;
            case 2:
                cout << "Skin specialist." << endl;
                break;
            case 3:
                cout << "Cardic specialist." << endl;
                break;
            }
            emergency *q = p -> patient;
            while (q != NULL) {
                cout << "\n\tPATIENT\n";
                cout << "Patient name: " << q -> name << endl;
                cout << "Patient age: " << q -> age << endl;
                cout << "Patient address: " << q -> address << endl;
                q = q -> forw;
            }
            p = p -> next;
        }
    }
    else cout << "\nNothing to display!\n";
}

void displayPatients() {
    if (start != NULL) {
        emergency *a = start;
        while (a != NULL) {
            cout << "\n\t\tAll Patients\n";
            cout << "Patient name: " << a -> name << endl;
            cout << "Patient age: " << a -> age << endl;
            cout << "Patient address: " << a -> age << endl;
            a = a -> forw;
        }
    }
    else cout << "\nNothing to display!\n";
}

int main() {
    int opt;
    do {
        cout << "\n\t\tHOSPITAL MANAGEMENT SYSTEM\n";
        cout << "\nEnter 1 to add a Doctor \nEnter 2 to add a Patient"
                "\nEnter 3 to remove a Patient"
                "\nEnter 4 to display all details"
                "\nEnter 5 to display patients only"
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
        case 5:
            displayPatients();
            break;
        default:
            cout << "\nYou selected invalid option!";
            break;
        }
    } while (opt != 0);
    return 0;
}