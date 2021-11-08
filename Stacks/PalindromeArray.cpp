#include<iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

class Palindrome {
    public:
    string exp;
    char *arr1;
    char *arr2;
    int top1;
    int top2;
    int size;

    Palindrome() {
        cout << "\n\t\tPalindrome Checker\n";
        cout << "\nEnter a word: ";
        cin >> exp;
        size = exp.length();
        top1 = -1;
        top2 = -1;
        arr1 = new char[size];
        arr2 = new char[size];
    }

    void push1(char x) {
        arr1[++top1] = x;
    }

    void push2(char x) {
        arr2[++top2] = x;
    }
    bool checker() {
        bool check;
        for (int i = top1; i >= 0; i--) {
            if (arr1[i] == arr2[i]) {
                check = true;
            }
            else {
                check = false;
                break;
            }
        }
        return check;
    }
};

int main() {
    Palindrome p;
    for (int i = 0; i < p.size; i++) {
        p.push1(p.exp[i]);
    }
    for (int i = p.top1; i >= 0; i--) {
        p.push2(p.arr1[i]);
    }
    bool check = p.checker();
    if (check == true) 
        cout << "PALINDROME!" << endl;
    else cout << "Not a PALINDROME!" << endl;
}
