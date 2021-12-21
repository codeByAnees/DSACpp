#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int adminID = 0;
string adminPass = "1234"; 

struct adminLogIn {
    int id;
    string name;
    string password;
};

bool adminLogin() {
    adminLogIn *add = new adminLogIn;
    cout << "\nEnter ID: ";
    cin >> add -> id;
    cout << "Enter password: ";
    cin >> add -> password;
    if (add -> id == adminID && add -> password == adminPass) {
        return true;
    }
    else return false;
}

vector<string> menu = {"Fries", "Pizza", "Pasta", "Burger"}; 
void addMenu() {
    if (adminLogin()) {
        string temp;
        cout << "Enter new dish: ";
        cin >> temp;
        menu.push_back(temp);
        cout << "\nSuccessful\n";
    }
    else cout << "Invalid password!";
}

void delMenu() {
    if (adminLogin()) {
        string temp;
        cout << "Enter dish to del: ";
        cin >> temp;
        int tempindex = -1;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i] == temp) {
                tempindex = i;
                break;
            }
        }
        if (tempindex == -1) cout << "Not found";
        else {
            menu.erase(menu.begin() + tempindex);
            cout << "\nSuccessful\n";
        }
    }
    else cout << "Invalid password!";
}

void display() {
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << endl;
    }
}

// int main() {
//     addMenu();
//     delMenu();
//     display();
// }


//*******************************************************************************************//

struct riderLogin {
    string Logid;
    string Logpassw;
    riderLogin *rNext = NULL;
};

riderLogin *logHead = NULL, *logTail = NULL, *logCur = NULL;

bool riderLogIN() {
    string tempid, tempPass; 
    cout << "\nEnter ID: ";
    cin >> tempid;
    cout << "Enter password: ";
    cin >> tempPass;
    bool validation = false;
    riderLogin *p = logHead;
    while (p != NULL) {
        if (p -> Logid == tempid && p -> Logpassw == tempPass) {
            validation = true;
        }
        p = p -> rNext;
    }
    return validation;
}

struct rideRecord {
    string order;
    string address;
    double amount;
    rideRecord *forw = NULL;
};
struct rider {
    string id;
    string name;
    string bikeRegNo;
    int totalOrders;
    rider *next = NULL;
    rideRecord *record = NULL;
};

rider *head = NULL, *tail = NULL, *current = NULL;

void registerRider() {
    current = new rider;
    logCur = new riderLogin;
    cout << "\nEnter your name: ";
    cin >> current -> name;
    cout << "Set your logIn ID: ";
    cin >> current -> id;
    logCur -> Logid = current -> id; 
    cout << "Set your password: ";
    cin >> logCur -> Logpassw;
    cout << "Enter bike registration number: ";
    cin >> current -> bikeRegNo;
    if (head == NULL && logHead == NULL) {
        head = tail = current;
        logHead = logTail = logCur;
    }
    else {
        tail -> next = current;
        tail = current;
        logTail -> rNext = logCur;
        logTail = logCur;
    }
}


int main() {
    registerRider();
    bool temp = riderLogIN();
    if (temp == true) {
        cout << "True";
    }
    else cout << "False";
}

//**********************************************************************************//




