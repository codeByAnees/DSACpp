#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct rider {
    int id;
    string name;
    string bikeRegNo;
    int totalOrders;
    rider *next = NULL;
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


