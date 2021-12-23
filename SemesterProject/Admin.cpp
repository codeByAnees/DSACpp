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
    cout << "\n\t\tA D M I N\n";
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
    double tempbill = 0.0;
    cout << "Enter new dish: ";
    cin >> temp;
    cout << "Enter cost: ";
    cin >> tempbill;
    menu.push_back(temp);
    bill.push_back(tempbill);
    cout << "\nSuccessful\n";
}

void delMenu() {
    string temp;
    cout << "Enter dish to remove: ";
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
        bill.erase(bill.begin() + tempindex);
        cout << "\nSuccessful\n";
    } 
}


struct rideRecord {
    string order;
    string address;
    double amount = 0.0;
    rideRecord *forw = NULL;
};
struct rider {
    string id;
    string password;
    string name;
    string bikeRegNo;
    int totalOrders = 0;
    rider *next = NULL;
    rideRecord *record = NULL;
};

rider *head = NULL, *tail = NULL, *current = NULL;
rider *s = NULL;
bool riderLogIN() {
    string tempid, tempPass;
    cout << "\n\t\tR I D E R\n";
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
    if (p != NULL) {
        if (q != NULL) {
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
        if (tempH == NULL) {
            tempH = tempT = p;
        }
        else {
            tempT -> next = p;
            tempT = p;
        }
    }
    else cout << "\nNo rider available\n";
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

void Rider() {
    int opt;
    cout << "\nEnter 1 to register as a new rider"
    "\nEnter 2 to access rider profile: ";
    cin >> opt;
    if (opt == 1) {
        registerRider();
    }
    else riderProfile();
}


struct customerRecord {
    string order;
    double amount = 0.0;
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
customer *person = NULL;
bool cutomerLogIN() {
    string tempid, tempPass; 
    cout << "\n\t\tC U S T O M E R\n";
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
    cout << "\n\t\tM E N U\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << endl;
    }
}

vector<string> orDer;
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
                orDer.push_back(choose);
                tbill += bill[i];
            }
        }
        if (tt == tbill) {
            cout << "Sorry, we don't offer selected item";
        }
        cout << "\nEnter 1 to continue ordering or \nEnter any other key to exit: ";
        cin >> opt;
        if (opt != 1) {
            break;
        }
    }
}

struct orders {
    string Order;
    double bill = 0.0;
    orders *Next = NULL;
};
orders *orderH = NULL, *orderT = NULL, *orderC = NULL;

void placeOrder() {
    int choice;
    cout << "\nEnter 1 if you are a member \nEnter 2 if you are not a member: ";
    cin >> choice;
    orderC = new orders;
    if (choice == 1) {
        if (cutomerLogIN()) {
            ordering();
            string tempOrder;
            for (int i = 0; i < orDer.size(); i++) {
                tempOrder += orDer[i] + " ";
            }
            newRide(tempOrder, person -> address, tbill);
            customerRecord *curren = new customerRecord;
            curren -> order = tempOrder;
            curren -> amount = tbill;
            if (person -> record == NULL) {
                person -> record = curren;
            }
            else {
                curren -> Cforw = person -> record;
                person -> record = curren;
            }
            orderC -> Order = tempOrder;
            orderC -> bill = tbill;
        }
        else cout << "\nInvalid password or user ID!\n";
    }
    else {
        ordering();
        string tempOrder;
        for (int i = 0; i < orDer.size(); i++) {
            tempOrder += orDer[i] + " ";
        }
        string address;
        cout << "Enter your address: ";
        cin >> address;
        orderC -> Order = tempOrder;
        orderC -> bill = tbill;
        newRide(tempOrder, address, tbill);
    }
    if (orderH == NULL) {
        orderH = orderT = orderC;
    }
    else {
        orderT -> Next = orderC;
        orderT = orderC;
    }
}

void displayMembers() {
    customer *p = Chead;
    while (p != NULL) {
        cout << "ID: " << p -> id << endl;
        cout << "Name: " << p -> name << endl;
        cout << "Address: " << p -> address << endl;
        p = p -> Cnext;
    }
}

void memberRecord() {
    if (cutomerLogIN()) {
        customerRecord *q = person -> record;
        while (q != NULL) {
            cout << "Order: " << q -> order << endl;
            cout << "Bill :" << q -> amount << endl;
            q = q -> Cforw;
        }
    }
}

void Customer() {
    int opt;
    do {
        cout << "\nEnter 1 to register as a member \nEnter 2 to place an order"
        "\nEnter 3 to access profile(members) \nEnter 0 to exit: ";
        cin >> opt;
        switch(opt) {
            case 0:
                break;
            case 1:
                newCustomerReg();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                memberRecord();
                break;
        }
    } while (opt != 0);
}

double calEarning() {
    orders *p = orderH;
    double earnings = 0.0;
    while (p != NULL) {
        earnings += p -> bill;
        p = p -> Next;
    }
    return earnings;
}

void displayRiders() {
    rider *p = head;
    while (p != NULL) {
        cout << "ID: " << p -> id << endl;
        cout << "Name: " << p -> name << endl;
        cout << "Bike regNo: " << p -> bikeRegNo << endl;
        p = p -> next;
    }
}

void removeRider() {
    displayRiders();
    string Id;
    cout << "Enter ID of member to remove: ";
    cin >> Id;
    rider *p = head, *q = NULL;
    while (p -> id != Id && p != NULL) {
        q = p;
        p = p -> next;
    }
    if (p -> id == Id && q == NULL) {
        head = p -> next;
        delete p;
    }
    else if (p -> id == Id && p == tail && q != NULL) {
        q -> next = NULL;
        tail = q;
        delete p;
    }
    else {
        q -> next = p -> next;
        delete p;
    }
}

void adminRider() {
    if (adminLogin()) {
        int opt;
        do {
            cout << "\nEnter 1 to add a rider \nEnter 2 remove a rider \nEnter 3 to view riders record"
            "\nEnter 0 to exit -->";
            cin >> opt;
            switch(opt) {
                case 0:
                    break;
                case 1:
                    registerRider();
                    break;
                case 2:
                    removeRider();
                    break;
                case 3:
                    riderOrdersRecord();
                    break;
            }
        } while (opt != 0);
    }
    else cout << "\nInvalid password or user ID!\n";
}

void removeMember() {
    displayMembers();
    string Id;
    cout << "Enter ID of member to remove: ";
    cin >> Id;
    customer *p = Chead, *q = NULL;
    while (p -> id != Id && p != NULL) {
        q = p;
        p = p -> Cnext;
    }
    if (p -> id == Id && q == NULL) {
        Chead = p -> Cnext;
        delete p;
    }
    else if (p -> id == Id && p == Ctail && q != NULL) {
        q -> Cnext = NULL;
        Ctail = q;
        delete p;
    }
    else {
        q -> Cnext = p -> Cnext;
        delete p;
    }
}

void adminMember() {
    if (adminLogin()) {
        int opt;
        do {
            cout << "\nEnter 1 to add a member \nEnter 2 remove a member"
            "\nEnter 3 to display all members \nEnter 0 to exit -->";
            cin >> opt;
            switch(opt) {
                case 0:
                    break;
                case 1:
                    newCustomerReg();
                    break;
                case 2:
                    removeMember();
                    break;
                case 3:
                    displayMembers();
                    break; 
            }
        } while (opt != 0);
    }
    else cout << "\nInvalid password or user ID!\n";
}

void admin() {
    if (adminLogin()) {
        int opt;
        do {
            cout << "\nEnter 1 to add item to menu \nEnter 2 delete item from menu \nEnter 3 to display menu"
            "\nEnter 4 to access rider profile \nEnter 5 to access members profiles"
            "\nEnter 6 to calculate earnings \nEnter 0 to exit--> ";
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
                    adminRider();
                    break;
                case 5:
                    adminMember();
                    break;
                case 6:
                    cout << "Total earnings are: " << calEarning() << endl;
                    break;
            }
        } while (opt != 0);
    }
    else cout << "\nInvalid password or user ID!\n";
}

int main() {
    int opt;
    do {
        cout << "\nEnter 1 for Admin menu \nEnter 2 for customer menu" 
           "\nEnter 3 for rider menu"
           "\nEnter 4 for ordering food"
           "\nEnter 0 to QUIT --> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                admin();
                break;
            case 2:
                Customer();
                break;
            case 3:
                Rider();
                break;
            case 4:
                placeOrder();
                break;
        }
    } while (opt != 0);
}