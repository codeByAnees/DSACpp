#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class PizzaHut {
    public:
    string *name;
    string *address;
    string *order;
    double *bill;
    const int size = 400;
    int choice;
    int front;
    int rear;

    PizzaHut() {
        name = new string[size];
        address = new string[size];
        order = new string[size];
        bill = new double[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        else return false;
    }

    void addToFront(string n, string a, string o, double b) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front != 0) {
            front--;
        }
        else {
            rear++;
            for (int i = rear; i > front; i--) {
                name[i] = name[i - 1];
                address[i] = address[i - 1];
                order[i] = order[i - 1];
                bill[i] = bill[i - 1];
            }
        }
        name[front] = n;
        address[front] = a;
        order[front] = o;
        bill[front] = b;
    }

    void addToLast(string n, string a, string o, double b) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front != 0) {
            front--;
            for (int i = front; i < rear; i++) {
                name[i] = name[i + 1];
                address[i] = address[i + 1];
                order[i] = order[i + 1];
                bill[i] = bill[i + 1];
            }
        }
        else {
            rear++;
        }
        name[rear] = n;
        address[rear] = a;
        order[rear] = o;
        bill[rear] = b;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            cout << "\n\t\tOrder Details";
            cout << "\nName: " << name[front] << endl;
            cout << "Address: " << address[front] << endl;
            cout << "Order: " << order[front] << endl;
            cout << "Bill: " << bill[front] << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
        }
    }

    void removeLast() {
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            cout << "\n\t\tOrder Details";
            cout << "\nName: " << name[rear] << endl;
            cout << "Address: " << address[rear] << endl;
            cout << "Order: " << order[rear] << endl;
            cout << "Bill: " << bill[rear] << endl;
            if (front == rear) {
                front = rear = -1;
            }
            else {
                rear--;
            }
        }
    }

    void orderInfo() {
        int i;
        string name, address, order;
        double bill;
        cout << "\nEnter Customer Name: ";
        cin >> name;
        cout << "Enter Customer Address: ";
        cin >> address;
        cout << "Select order: \nEnter--> \n\t1 for Small pizza \n\t2 for Medium pizza"
                "\n\t3 for Large Pizza \n\t4 for Extra large pizza: ";
        cin >> i;
        switch(i) {
            case 1:
                order = "Small pizza + 250ml cold drink";
                bill = 549.0;
                break;
            case 2:
                order = "Medium pizza + 500ml coke";
                bill = 849.0;
                break;
            case 3:
                order = "Large pizza + 1000ml coke";
                bill = 1199.0;
                break;
            case 4:
                order = "Extra large pizza + 2000ml coke";
                bill = 1649.0;
                break;
            default:
                cout << "Invalid choice!";
                break;
        }
        if (choice == 1) {
            addToFront(name, address, order, bill);
        }
        else {
            addToLast(name, address, order, bill);
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << "\n\t\tOrder Details";
                cout << "\nName: " << name[i] << endl;
                cout << "Address: " << address[i] << endl;
                cout << "Order: " << order[i] << endl;
                cout << "Bill: " << bill[i] << endl;
            }
        }
    }
};

int main() {
    PizzaHut q;
    int x;
    do {
        cout << "\nEnter 1 to place an order at front serving unit" 
                "\nEnter 2 to place an order at rear serving unit" 
                "\nEnter 3 to serve from front unit"
                "\nEnter 4 to serve from rear unit " 
                "\nEnter 5 to display all orders"
                "\nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
                q.choice = 1;
                q.orderInfo();
                cout << "\nSuccessful!\n";
                break;
            case 2:
                q.choice = 2;
                q.orderInfo();
                cout << "\nSuccessful!\n";
                break;
            case 3:
                if (!q.isEmpty()) 
                    q.removeFront();
                else
                    cout << "\nNo customer!" << endl;
                break;
            case 4:
                if (!q.isEmpty()) 
                    q.removeLast();
                else
                    cout << "\nNo customer!" << endl;
                break;
            case 5:
                q.display();
                break;
            default:
                cout << "\nInvalid choice!\n";
                break;
        }
    } while (x != 0);
}