#include<iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

struct ride {
    string riderName;
    double distance;
    double charges;
    ride *forw = NULL;
};

struct car {
    string driverName;
    string carName;
    string regNo;
    int carType;
    double km;
    car *next = NULL, *prev = NULL;
    ride *rideDetails = NULL;
};

car *head = NULL, *tail = NULL, *current = NULL;

void insertCarInfo() {
    current = new car;
    cout << "\n\t\tEnter Car Details";
    cout << "\nEnter your name: ";
    cin >> current -> driverName;
    cout << "Enter car name: ";
    cin >> current -> carName;
    cout << "Enter Reg No: ";
    cin >> current -> regNo;
    cout << "Enter car type(1/2): ";
    cin >> current -> carType;
    if (head == NULL) {
        head = tail = current;
    }
    else {
        tail -> next = current;
        current -> prev = tail;
        tail = current;
    }
    cout << "\nRegistration Successful!\n";
}


void insertRideInfo() {
    car *p = head;
    cout << "\n\t\tCars Available\n";
    while (p != NULL) {
        cout << p -> carName << endl;
        p = p -> next;
    }
    string choice;
    cout << "\nEnter name of car for ride(Capital): ";
    cin >> choice;
    car *q = head;
    while (q -> carName != choice && q != NULL) {
        q = q -> next;
    }

    if (q -> carName == choice) {
        ride *current = new ride;
        cout << "\n\t\tEnter Ride Details\n";
        cout << "Enter rider name: ";
        cin >> current -> riderName;
        cout << "Distance in km: ";
        cin >> current -> distance;
        q -> km += current -> distance;
        current -> charges = current -> distance * 11;
        if (q -> rideDetails == NULL) {
            q -> rideDetails = current;
        }
        else {
            current -> forw = q -> rideDetails;
            q -> rideDetails = current;
        }
        cout << "\nSuccessful!\n";
    }
    else cout << "\nYou entered wrong car name!\n";
}


void calEarning() {
    car *p = head;
    if (p != NULL && p -> rideDetails != NULL) {
        double earnings = 0.0;
        cout << "\n\t\tAll Cars\n";
        while (p != NULL) {
            cout << p -> carName << endl;
            p = p -> next;
        }
        string choice;
        cout << "\nEnter car name to check earnings: ";
        cin >> choice;
        car *q = head;
        while (q -> carName != choice && q != NULL) {
            q = q -> next;
        }
        if (q -> carName == choice) {
            ride *p = q -> rideDetails;
            while (p != NULL) {
                earnings += p -> charges;
                p = p -> forw;
            }
            cout << "\nTotal earnings of this car " << earnings << endl;
        }
        else cout << "\nCar not found!\n";
    }
    else cout << "\nNo earnings yet!\n";
}


void allEarning() {
    car *p = head;
    if (p != NULL && p -> rideDetails != NULL) {
        double earning = 0.0;
        while (p != NULL) {
            ride *q = p -> rideDetails;
            while (q != NULL) {
                earning += q -> charges;
                q = q -> forw;
            }
            p = p -> next;
        }
        cout << "\nTotal earning of all cars " << earning << endl;
    }
    else cout << "\nNo earnings yet! " << endl;
}


void displayCarDetails() {
    car *p = head;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\n\t\tCar Details\n";
            cout << "Driver Name: " << p -> driverName << endl;
            cout << "Car Name : " << p -> carName << endl;
            cout << "Reg No. " << p -> regNo << endl;
            cout << "Car type: " << p -> carType << endl;
            cout << "No of KMs: " << p -> km << endl;
            p = p -> next;
        }
    }
    else cout << "\nNo information to display!" << endl;
}


void displayType2() {
    car *p = head;
    if (p != NULL) {
        while (p != NULL) {
            if (p -> carType == 2) {
                cout << "\n\t\tCar Details\n";
                cout << "Driver Name: " << p -> driverName << endl;
                cout << "Car Name : " << p -> carName << endl;
                cout << "Reg No. " << p -> regNo << endl;
                cout << "Car type: " << p -> carType << endl;
                cout << "No of KMs: " << p -> km << endl;
                p = p -> next;
            }
            else p = p -> next;
        }
    }
    else cout << "\nNo information to display!" << endl;
}


void carRideDetails() {
    car *p = head;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\n\t\tCar Details";
            cout << "\nDriver Name: " << p -> driverName << endl;
            cout << "Car Name : " << p -> carName << endl;
            cout << "Reg No. " << p -> regNo << endl;
            cout << "Car type: " << p -> carType << endl;
            cout << "No of KMs: " << p -> km << endl;
            ride *n = p -> rideDetails;
            while (n != NULL) {
                cout << "\n\tRide Details";
                cout << "\nRider Name: " << n -> riderName << endl;
                cout << "Distance in KM: " << n -> distance << endl;
                cout << "Charges: " << n -> charges << endl;
                n = n -> forw;
            }
            p = p -> next;
        }
    }
    else cout << "\nNo information to display!" << endl;
}


void rideDetails() {
    car *p = head;
    if (p != NULL && p -> rideDetails != NULL) {
        while (p != NULL) {
            ride *n = p -> rideDetails;
            while (n != NULL) {
                cout << "\n\tRide Details";
                cout << "\nRider Name: " << n -> riderName << endl;
                cout << "Distance in KM: " << n -> distance << endl;
                cout << "Charges: " << n -> charges << endl;
                n = n -> forw;
            }
            p = p -> next;
        }
    }
    cout << "\nNothing to display!" << endl;
}


int main() {
    int opt;
    do {
        cout << "\n\t\tCAREEM MANAGEMENT SYSTEM\n";
        cout << "\nEnter 1 to REGISTER new car \nEnter 2 to ADD a new ride"
        "\nEnter 3 to display DETAILS of all cars \nEnter 4 to dispaly TYPE-2 cars"
        "\nEnter 5 to get RIDES detail \nEnter 6 to get car and ride DETAILS"
        "\nEnter 7 to display EARNINGS of all cars \nEnter 8 to get earnings of a SPECIFIC car"
        "\nEnter 0 to QUIT ---> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                insertCarInfo();
                break;
            case 2:
                insertRideInfo();
                break;
            case 3:
                displayCarDetails();
                break;
            case 4:
                displayType2();
                break;
            case 5:
                rideDetails();
                break;
            case 6:
                carRideDetails();
                break;
            case 7:
                allEarning();
                break;
            case 8:
                calEarning();
                break;
            default:
                cout << "\nYou selected invalid option!";
                break;
            } 
    } while (opt != 0);
        return 0;
}