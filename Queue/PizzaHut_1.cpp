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

    void enqueue(string n, string a, string o, double b) {
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = ((rear + 1) % size);
        }
        name[rear] = n;
        address[rear] = a;
        order[rear] = o;
        bill[rear] = b;
    }

    void dequeue() {
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
                front = ((front + 1) % size);
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "\nEmpty\n";
        }
        else {
            int i = front, j = rear;
            while (i != j) {
                cout << "\n\t\tOrder Details";
                cout << "\nName: " << name[i] << endl;
                cout << "Address: " << address[i] << endl;
                cout << "Order: " << order[i] << endl;
                cout << "Bill: " << bill[i] << endl;
                i = ((i + 1) % size);
            }
            cout << "\n\t\tOrder Details";
            cout << "\nName: " << name[i] << endl;
            cout << "Address: " << address[i] << endl;
            cout << "Order: " << order[i] << endl;
            cout << "Bill: " << bill[i] << endl;
        }
    }
};

int main() {
    PizzaHut q;
    int x, i;
    string name, address, order;
    double bill;
    do {
        cout << "\nEnter 1 to place an order \nEnter 2 to serve the order" 
        "\nEnter 3 to display all orders \nEnter 0 to quit --> ";
        cin >> x;
        switch(x) {
            case 0:
                break;
            case 1:
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
                q.enqueue(name, address, order, bill);
                cout << "\nSuccessful!\n";
                break;
            case 2:
                if (!q.isEmpty()) 
                    q.dequeue();
                else
                    cout << "\nNo customer!" << endl;
                break;
            case 3:
                q.display();
                break;
        }
    } while (x != 0);
}