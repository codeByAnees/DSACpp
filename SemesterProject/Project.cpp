#include<iostream>
#include<climits>
#include<string>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;
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
    cout << "\nEnter new dish: ";
    cin >> temp;
    cout << "Enter cost: ";
    cin >> tempbill;
    menu.push_back(temp);
    bill.push_back(tempbill);
    cout << "\nSuccessful\n";
}

void delMenu() {
    string temp;
    cout << "\nEnter dish to remove: ";
    cin >> temp;
    int tempindex = -1;
    for (int i = 0; i < menu.size(); i++) {
        if (menu[i] == temp) {
            tempindex = i;
            break;
        }
    }
    if (tempindex == -1) cout << "\nNot found\n";
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

vector<string> addresses;
int totalAdd = 0;
void deliveryAddresses() {
    rider *p = head;
    rideRecord *q = p -> record;
    while (q != NULL) {
        totalAdd++;
        addresses.push_back(q -> address);
        q = q -> forw;
    }
}

void dijkstra(int **graph, int n) {
    int distance[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for (int p = 0; p < n; p++) {
        int min = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (min == -1 || distance[j] < distance[min])) {
                min = j;
            }
        }
        visited[min] = true;
        for (int k = 0; k < n; k++) {
            if (graph[min][k] != 0 && (distance[min] + graph[min][k]) < distance[k]) {
                distance[k] = distance[min] + graph[min][k];
            }
        }
    }
    cout << "Vertex     Distance from source" << endl;
    for (int i = 1; i < n; i++) {
        cout << addresses[i] << "              " << distance[i] << endl;
    }
}

void getDistance() {
    deliveryAddresses();
    int **graph = new int*[totalAdd];
    for (int i = 0; i < totalAdd; i++) {
        graph[i] = new int[totalAdd];
    }
    for (int i = 0; i < totalAdd; i++) {
        for (int j = 0; j < totalAdd; j++) {
            cout << "Enter distance of " << addresses[i] << " to " << addresses[j] << endl;
            cin >> graph[i][j];
        }
    }
    dijkstra(graph, totalAdd);
}

void registerRider() {
    current = new rider;
    cout << "\nSet logIn ID: ";
    cin >> current -> id; 
    cout << "Set password: ";
    cin >> current -> password;
    cout << "Enter name of rider: ";
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
    cout << "\nSuccessful\n";
}

rider *tempH = NULL, *tempT = NULL;
void newRide(string orderr, string addresss, double bill) {
    rider *p = head;
    rider *q = tempH;
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

void riderOrdersRecord() {
    rider *a = head;
    if (a != NULL) {
        while (a != NULL) {
            cout << "\nRider name: " << a -> name << endl;
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
    else cout << "\nNo orders yet!\n";
}

void riderProfile() {
    if (riderLogIN()) {
        cout << "\nRider name: " << s -> name << endl;
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
    else cout << "\nWrong password or user ID\n";
}

void Rider() {
    int opt;
    do {
        cout << "\nEnter 1 to register as a new rider"
        "\nEnter 2 to access rider profile \nEnter 0 to exit --> ";
        cin >> opt;
        switch(opt) {
            case 0:
                break;
            case 1:
                registerRider();
                break;
            case 2:
                riderProfile();
                break;
        }
    } while (opt != 0);
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
    cout << "\nSet log-in ID: ";
    cin >> Ccurrent -> id;
    cout << "Set password: ";
    cin >> Ccurrent -> password;
    cout << "Enter name: ";
    cin >> Ccurrent -> name;
    cout << "Enter address: ";
    cin >> Ccurrent -> address;
    if (Chead == NULL) {
        Chead = Ctail = Ccurrent;
    }
    else {
        Ctail -> Cnext = Ccurrent;
        Ctail = Ccurrent;
    }
    cout << "\nSuccessful\n";
}

void displayMenu() {
    cout << "\n\t\tM E N U\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << " -> " << bill[i] << endl;
    }
}

vector<string> orderRec;
double totalBill;
void ordering() {
    int opt;
    while (true) {
        double tempBill = totalBill;
        string choose;
        displayMenu();
        cin >> choose;
        for (int i = 0; i < menu.size(); i++) {
            if (menu[i] == choose) {
                orderRec.push_back(choose);
                totalBill += bill[i];
            }
        }
        if (tempBill == totalBill) {
            cout << "\nSorry, we don't offer selected item\n";
        }
        cout << "\nEnter 1 to continue ordering or \nEnter any other key to exit: ";
        cin >> opt;
        if (opt != 1) {
            break;
        }
    }
}

rideRecord *dHead = NULL, *dTail = NULL, *dCurr = NULL;

rideRecord *orderRecH = NULL, *orderRecT = NULL, *orderRecCu = NULL;
void placeOrder() {
    int choice, option;
    bool check;
    string tempOrder;
    string address;
    cout << "\nEnter 1 if you are a member \nEnter 2 if you are not a member: ";
    cin >> choice;
    orderRecCu = new rideRecord;
    if (choice == 1) {
        if (cutomerLogIN()) {
            ordering();
            for (int i = 0; i < orderRec.size(); i++) {
                tempOrder += orderRec[i] + ", ";
            }
            cout << "\nEnter 1 for dine-in \nEnter 2 for delivery: ";
            cin >> option;
            if (option == 1) {
                cout << "\nOk. Your order is getting ready!\n";
                check = true;
                customerRecord *curren = new customerRecord;
                curren -> order = tempOrder;
                curren -> amount = totalBill;
                if (person -> record == NULL) {
                    person -> record = curren;
                }
                else {
                    curren -> Cforw = person -> record;
                    person -> record = curren;
                }
            }
            else {
                rider *p = head;
                if (p != NULL) {
                    dCurr = new rideRecord;
                    dCurr -> order = tempOrder;
                    dCurr -> address = person -> address;
                    dCurr -> amount = totalBill;
                    if (dHead == NULL) {
                        dHead = dTail = dCurr;
                    }
                    else {
                        dTail -> forw = dCurr;
                        dTail = dCurr;
                    }
                    address = person -> address;
                    check = true;
                    customerRecord *curren = new customerRecord;
                    curren -> order = tempOrder;
                    curren -> amount = totalBill;
                    if (person -> record == NULL) {
                        person -> record = curren;
                    }
                    else {
                        curren -> Cforw = person -> record;
                        person -> record = curren;
                    }
                    cout << "\nYour order will be deliverd soon!\n";
                }
                else {
                    cout << "\nSorry, no rider available at the moment!\n";
                    int x;
                    cout << "\nEnter 1 for dine-in \nEnter 2 to cancel: ";
                    cin >> x;
                    if (x == 1) {
                        cout << "\nOk. Your order is getting ready!\n";
                        check = true;
                        customerRecord *curren = new customerRecord;
                        curren -> order = tempOrder;
                        curren -> amount = totalBill;
                        if (person -> record == NULL) {
                            person -> record = curren;
                        }
                        else {
                            curren -> Cforw = person -> record;
                            person -> record = curren;
                        }
                    }
                    else {
                        cout << "\nSorry for inconvenience";
                        check = false;
                    }
                }
            }
        }
        else cout << "\nInvalid password or user ID!\n";
    }
    else {
        ordering();
        for (int i = 0; i < orderRec.size(); i++) {
            tempOrder += orderRec[i] + ", ";
        }
        cout << "\nEnter 1 for dine-in \nEnter 2 for delivery: ";
        cin >> option;
        if (option == 1) {
            cout << "\nOk. Your order is getting ready!\n";
            check = true;
        }
        else {
            rider *p = head;
            if (p != NULL) {
                cout << "Enter address to deliver: ";
                cin >> address;
                dCurr = new rideRecord;
                dCurr -> order = tempOrder;
                dCurr -> address = address;
                dCurr -> amount = totalBill;
                if (dHead == NULL) {
                    dHead = dTail = dCurr;
                }
                else {
                    dTail -> forw = dCurr;
                    dTail = dCurr;
                }
                check = true;
                cout << "\nYour order will be deliverd soon!\n";
            }
            else {
                cout << "\nSorry, no rider available at the moment!\n";
                int x;
                cout << "\nEnter 1 for dine-in \nEnter 2 to cancel: ";
                cin >> x;
                if (option == 1) {
                    cout << "\nOk. Your order is getting ready!\n";
                    check = true;
                }
                else {
                    cout << "\nSorry for inconvenience";
                    check = false;
                }
            }
        }
    }
    if (check) {
        orderRecCu -> order = tempOrder;
        orderRecCu -> address = address;
        orderRecCu -> amount = totalBill;
        if (orderRecH == NULL) {
            orderRecH = orderRecT = orderRecCu;
        }
        else {
            orderRecT -> forw = orderRecCu;
            orderRecT = orderRecCu;
        }
    }
    totalBill = 0.0;
    orderRec.clear();
    cout << "\nSuccessful\n";
}

void displayMembers() {
    customer *p = Chead;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\nID: " << p -> id << endl;
            cout << "Name: " << p -> name << endl;
            cout << "Address: " << p -> address << endl;
            p = p -> Cnext;
        }
    }
    else cout << "\nNo member to display!\n";
}

void memberRecord() {
    if (cutomerLogIN()) {
        customerRecord *q = person -> record;
        while (q != NULL) {
            cout << "\nOrder: " << q -> order << endl;
            cout << "Bill : " << q -> amount << endl;
            q = q -> Cforw;
        }
    }
    else cout << "\nInvalid password or user ID!\n";
}

void Customer() {
    int opt;
    do {
        cout << "\nEnter 1 to register as a member \nEnter 2 to place an order"
        "\nEnter 3 to access profile(members) \nEnter 0 to exit --> ";
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

void displayOrderRecAndCalEarning() {
    rideRecord *p = orderRecH;
    if (p != NULL) {
        double earnings = 0.0;
        while (p != NULL) {
            cout << "\n\t\tO R D E R S";
            cout << "\nOrder: " << p -> order << endl;
            cout << "Address: " << p -> address << endl;
            cout << "Order bill: " << p -> amount << endl;
            earnings += p -> amount;
            p = p -> forw;
        }
        cout << "\nTotal earnings are: " << earnings << endl;
    }
    else cout << "\nNo orders yet!\n";
}

void displayRiders() {
    rider *p = head;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\n\t\tR I D E R S";
            cout << "\nID: " << p -> id << endl;
            cout << "Name: " << p -> name << endl;
            cout << "Bike regNo: " << p -> bikeRegNo << endl;
            p = p -> next;
        }
    }
    else cout << "\nNo rider to display!\n";
}

void removeRider() {
    rider *p = head, *q = NULL;
    if (p != NULL) {
        displayRiders();
        string Id;
        cout << "\nEnter ID of member to remove: ";
        cin >> Id;
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
        cout << "\nSuccessful\n";
    }
    else cout << "\nNo rider to remove!\n";
}

void adminRider() {
    int opt;
    do {
        cout << "\nEnter 1 to add a rider \nEnter 2 remove a rider \nEnter 3 to view riders record"
        "\nEnter 0 to exit --> ";
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

void removeMember() {
    customer *p = Chead, *q = NULL;
    if (p != NULL) {
        displayMembers();
        string Id;
        cout << "\nEnter ID of member to remove: ";
        cin >> Id;
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
        cout << "\nSuccessful\n";
    }
    else cout << "\nNo member to remove!\n";
}

void adminMember() {
    int opt;
    do {
        cout << "\nEnter 1 to add a member \nEnter 2 remove a member"
        "\nEnter 3 to display all members \nEnter 0 to exit --> ";
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

void displayDeliveryOrders() {
    rideRecord *p = dHead;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\n\t\tO R D E R S";
            cout << "\nOrder: " << p -> order << endl;
            cout << "Address: " << p -> address << endl;
            cout << "Bill amount: " << p -> amount << endl;
            p = p -> forw;
        }
    }
    else cout << "\nNo order to deliver";
}

void assignOrder() {
    displayRiders();
    displayDeliveryOrders();
    rider *p = head;
    rideRecord *k = dHead;
    if (p != NULL && k != NULL) {
        cout << "\n\tOrder Delivery";
        string tempID;
        cout << "\nEnter rider ID: ";
        cin >> tempID;
        while (p -> id != tempID && p != NULL) {
            p = p -> next;
        }
        if (p == NULL) {
            cout << "\nRider not found";
        }
        else {
            rideRecord *Temp = new rideRecord;
            Temp -> order = dHead -> order;
            Temp -> address = dHead -> address;
            Temp -> amount = dHead -> amount;
            if (p -> record == NULL) {
                p -> record = Temp;
            }
            else {
                Temp -> forw = p -> record;
                p -> record = Temp;
            }
            dHead = k -> forw;
            delete k;
        }
    }
}

void admin() {
    if (adminLogin()) {
        int opt;
        do {
            cout << "\nEnter 1 to add item to menu \nEnter 2 delete item from menu \nEnter 3 to display menu"
            "\nEnter 4 to access rider profile \nEnter 5 to access members profiles"
            "\nEnter 6 to deliver order"
            "\nEnter 7 to view order record and total earnings \nEnter 0 to exit --> ";
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
                    assignOrder();
                    break;
                case 7:
                    displayOrderRecAndCalEarning();
                    break;
            }
        } while (opt != 0);
    }
    else cout << "\nInvalid password or user ID!\n";
}

int main() {
    int opt;
    do {
        cout << "\nEnter 1 for admin menu \nEnter 2 for customer menu" 
           "\nEnter 3 for rider menu"
           "\nEnter 4 for ordering food"
           "\nEnter 5 for getting shortest distance"
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
            case 5:
                getDistance();
                break;
        }
    } while (opt != 0);
}