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
    double *age;
    const int size = 400;
    int front;
    int rear;

    PizzaHut() {
        name = new string[size];
        age = new double[size];
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

    void enqueue(string n, double ag, string a, string o, double b) {
        if (isEmpty()) {
            front = rear = 0;
            name[rear] = n;
            age[rear] = ag;
            address[rear] = a;
            order[rear] = o;
            bill[rear] = b;
        }
        else {
            if (ag == age[front]) {
                if (front != 0) {
                    front--;
                    name[front] = name[front + 1];
                    age[front] = age[front + 1];
                    address[front] = address[front + 1];
                    order[front] = order[front + 1];
                    bill[front] = bill[front + 1];
                }
                else {
                    rear++;
                    for (int i = rear; i > front + 1; i--) {
                        age[i] = age[i - 1];
                        name[i] = name[i - 1];
                        address[i] = address[i - 1];
                        order[i] = order[i - 1];
                        bill[i] = bill[i - 1];
                    }
                }
                name[front + 1] = n;
                age[front + 1] = ag;
                address[front + 1] = a;
                order[front + 1] = o;
                bill[front + 1] = b;
            }
            else if (ag > age[front]) {
                if (front != 0) {
                    front--;
                }
                else {
                    rear++;
                    for (int i = rear; i > front; i--) {
                        age[i] = age[i - 1];
                        name[i] = name[i - 1];
                        address[i] = address[i - 1];
                        order[i] = order[i - 1];
                        bill[i] = bill[i - 1];
                    }
                }
                name[front] = n;
                age[front] = ag;
                address[front] = a;
                order[front] = o;
                bill[front] = b;
            }
            else if (ag < age[rear]) {
                rear++;
                name[rear] = n;
                age[rear] = ag;
                address[rear] = a;
                order[rear] = o;
                bill[rear] = b;
            }
            else {
                int i;
                for (i = front; i < rear; i++) {
                    if (ag > age[i]) {
                        break;
                    }
                }
                if (ag == age[i]) {
                    rear++;
                    for (int k = rear; k > i + 1; k--) {
                        age[k] = age[k - 1];
                        name[k] = name[k - 1];
                        address[k] = address[k - 1];
                        order[k] = order[k - 1];
                        bill[k] = bill[k - 1];
                    }
                    name[i + 1] = n;
                    age[i + 1] = ag;
                    address[i + 1] = a;
                    order[i + 1] = o;
                    bill[i + 1] = b;
                }
                else {
                    rear++;
                    for (int j = rear; j > i; j--) {
                        age[j] = age[j - 1];
                        name[j] = name[j - 1];
                        address[j] = address[j - 1];
                        order[j] = order[j - 1];
                        bill[j] = bill[j - 1];
                    }
                    name[i] = n;
                    age[i] = ag;
                    address[i] = a;
                    order[i] = o;
                    bill[i] = b;
                }
            }
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            cout << "\n\t\tOrder Details";
            cout << "\nName: " << name[front] << endl;
            cout << "Age: " << age[front] << endl;
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
        if (isEmpty()) {
            cout << "\nEmpty\n";
        }
        else {
            for (int i = front; i <= rear; i++) {
                cout << "\n\t\tOrder Details";
                cout << "\nName: " << name[i] << endl;
                cout << "Age: " << age[i] << endl;
                cout << "Address: " << address[i] << endl;
                cout << "Order: " << order[i] << endl;
                cout << "Bill: " << bill[i] << endl;
            }
        }
    }
};

int main() {
    PizzaHut q;
    int x, i;
    string name, address, order;
    double age, bill;
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
                cout << "Enter Customer age: ";
                cin >> age;
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
                q.enqueue(name, age, address, order, bill);
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