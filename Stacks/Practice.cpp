#include<iostream>
using std::cin;
using std::cout;
using std::endl;

bool check() {
    if (6 > 4) {
        return true;
    }
    else return false;
}

int main() {
    cout << check();
}