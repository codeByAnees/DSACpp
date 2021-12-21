#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int ID = 0;
string pass = "1234"; 

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
    if (add -> id == ID && add -> password == pass) {
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
    string
};

struct rider {
    int id;
    string name;
    string bikeRegNo;
    int totalOrders;
    rider *next = NULL;
    rideRecord *record = NULL;
};

struct rideRecord {
    string order;
    string address;
    double amount;
    rideRecord *forw = NULL;
};

rider *head = NULL, *tail = NULL, *current = NULL;

int count = 0;
void registerRider() {
    current = new rider;
    current -> id = ++count;
    cout << "\nEnter your name: ";
    cin >> current -> name;
    cout << "Enter bike registration number: ";
    cin >> current -> bikeRegNo;
    if (head == NULL) {
        head = tail = current;
    }
    else {
        tail -> next = current;
        tail = current;
    }
}

//**********************************************************************************//




