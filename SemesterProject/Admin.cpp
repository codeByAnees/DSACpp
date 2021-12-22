#include <iostream>
#include <string>
#include <cstring>
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
vector<double> bill = {100.0, 1000.0, 550.0, 600.0};
void addMenu() {
    string temp;
    double tempbill;
    cout << "Enter new dish: ";
    cin >> temp;
    cout << "Enter bill: ";
    cin >> tempbill;
    menu.push_back(temp);
    bill.push_back(tempbill);
    cout << "\nSuccessful\n";
}

void delMenu() {
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


//*******************************************************************************************//

struct rideRecord {
    string order;
    string address;
    double amount;
    rideRecord *forw = NULL;
};
struct rider {
    string id;
    string password;
    string name;
    string bikeRegNo;
    int totalOrders;
    rider *next = NULL;
    rideRecord *record = NULL;
};

rider *head = NULL, *tail = NULL, *current = NULL;
rider *s = NULL;
bool riderLogIN() {
    string tempid, tempPass; 
    cout << "\nEnter ID: ";
    cin >> tempid;
    cout << "Enter password: ";
    cin >> tempPass;
    bool validation = false;
    rider *p = head;
    while (p != NULL) {
        if (p -> id == tempid && p -> password == tempPass) {
            validation = true;
            break;
        }
        p = p -> next;
    }
    s = p;
    return validation;
}

void registerRider() {
    current = new rider;
    cout << "\nEnter your name: ";
    cin >> current -> name;
    cout << "Set your logIn ID: ";
    cin >> current -> id; 
    cout << "Set your password: ";
    cin >> current -> password;
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

rider *tempH = NULL, *tempT = NULL;

void newRide(string orderr, string addresss, double bill) {
    rider *p = head;
    rider *q = tempH;
    if (q == NULL) {

    }
    else {
        while (p != NULL) {
            while (p -> id != q -> id && q != NULL) {
                q = q -> next;
            }
            if (p -> id == q -> id) {
                p = p -> next;
            }
            else break;
        }
    }
    //while (true) {
        rideRecord *a = new rideRecord;
        a -> order = orderr;
        a -> address = addresss;
        a -> amount = bill;
        p -> totalOrders += 1;
        if (p -> record == NULL) {
            p -> record = a;
        }
        else {
            a -> forw = p -> record;
            p -> record = a;
        }
    //     int opt;
    //     cout << "Enter 1 to assign another order to this rider or \nEnter any other number to quit: ";
    //     cin >> opt;
    //     if (opt == 1) continue;
    //     else break;
    // }
    if (tempH == NULL) {
        tempH = tempT = p;
    }
    else {
        tempT -> next = p;
        tempT = p;
    }
}

void riderOrdersRecord() {
    rider *a = head;
    while (a != NULL) {
        cout << "Rider name: " << a -> name << endl;
        cout << "Bike RegNo: " << a -> bikeRegNo << endl;
        cout << "Total order: " << a -> totalOrders << endl;
        rideRecord *b = a -> record;
        while (b != NULL) {
            cout << "Order deliverd: " << b -> order << endl;
            cout << "Order address: " << b -> address << endl;
            cout << "Order bill: " << b -> amount << endl;
            b = b -> forw;
        }
        a = a -> next;
    }
}

void riderProfile() {
    if (riderLogIN()) {
        cout << "Rider name: " << s -> name << endl;
        cout << "Bike RegNo: " << s -> bikeRegNo << endl;
        cout << "Total order: " << s -> totalOrders << endl;
        rideRecord *n = s -> record;
        while (n != NULL) {
            cout << "Order deliverd: " << n -> order << endl;
            cout << "Order address: " << n -> address << endl;
            cout << "Order bill: " << n -> amount << endl;
            n = n -> forw;
        }
    }
    else cout << "Wrong password or user ID";
}

//**********************************************************************************//


struct customerRecord {
    string order;
    double amount;
    customerRecord *Cforw = NULL;
};
struct customer {
    string id;
    string password;
    string name;
    string address;
    customer *Cnext = NULL;
    customerRecord *record = NULL;
};

customer *Chead = NULL, *Ctail = NULL, *Ccurrent = NULL;
customer *person;
bool cutomerLogIN() {
    string tempid, tempPass; 
    cout << "\nEnter ID: ";
    cin >> tempid;
    cout << "Enter password: ";
    cin >> tempPass;
    bool validation = false;
    customer *p = Chead;
    while (p != NULL) {
        if (p -> id == tempid && p -> password == tempPass) {
            validation = true;
            break;
        }
        p = p -> Cnext;
    }
    person = p;
    return validation;
}

void newCustomerReg() {
    Ccurrent = new customer;
    cout << "Set your ID: ";
    cin >> Ccurrent -> id;
    cout << "Set your password: ";
    cin >> Ccurrent -> password;
    cout << "Enter your name: ";
    cin >> Ccurrent -> name;
    cout << "Enter your address: ";
    cin >> Ccurrent -> address;
    if (Chead == NULL) {
        Chead = Ctail = Ccurrent;
    }
    else {
        Ctail -> Cnext = Ccurrent;
        Ctail = Ccurrent;
    }
}

void displayMenu() {
    cout << "\nM E N U\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << endl;
    }
}

vector<string> order;
double tbill = 0;

void ordering() {
    int opt;
    while (true) {
        double tt = tbill;
        string choose;
        displayMenu();
        cin >> choose;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i] == choose) {
                order.push_back(choose);
                tbill += bill[i];
            }
        }
        if (tt == tbill) cout << "Sorry, we don't offer selected item";
        cout << "Enter 1 to continue ordering or \nEnter any other key to exit: ";
        cin >> opt;
        if (opt != 1) break;
    }
}

void placeOrder() {
    int choice;
    cout << "Enter 1 id you are a member \nEnter 2 if you are not a member: ";
    cin >> choice;
    if (choice == 1) {
        if (cutomerLogIN()) {
            ordering();
            string tempOrder;
            for (int i = 0; i < order.size(); i++) {
                tempOrder += order[i] + " ";
            }
            newRide(tempOrder, person -> address, tbill);
        }
    }
    else {
        ordering();
        string tempOrder;
        for (int i = 0; i < order.size(); i++) {
            tempOrder += order[i] + " ";
        }
        string address;
        cout << "Enter your address: ";
        cin >> address;
        newRide(tempOrder, address, tbill);
    }
}

void admin() {
    if (adminLogin()) {
        int opt;
        cout << "Enter 1 to add menu \nEnter 2 delete menu \nEnter 3 to display menu"
        "\nEnter 4 to check rider profile \nEnter 5 to calculate earning of the day"
        "\nEnter 0 to exit--> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                addMenu();
                break;
            case 2:
                delMenu();
                break;
            case 3:
                displayMenu();
                break;
            case 4:
                riderOrdersRecord();
                break;
            case 5:
                //calEarning();
                break;
        }
    }
    else cout << "Invalid password!";
}

int main() {
    int opt;
    do {
        cout << "Enter 1 for Admin \nEnter 2 for placing order" 
           "\nEnter 3 to access rider profile"
           "\nEnter 4 registering new customer"
           "\nEnter 0 to QUIT --> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                admin();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                riderProfile();
                break;
            case 4:
                newCustomerReg();
                break;
        }
    } while (opt != 0);
}