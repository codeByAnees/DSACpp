#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class SingleBalenced {
    public:
    string exp;
    char *sta;
    int top;
    int size;

    SingleBalenced() {
        cout << "\nEnter expression: ";
        cin >> exp;
        size = exp.length();
        sta = new char[size];
        top = -1;
    }

    bool isEmpty() {
        if (top == -1) return true;
        else return false;
    }

    void pushPop(char x) {
        if (x == '(' || x == '{' || x == '[') {
            sta[++top] = x;
        }
        else if (x == ')' || x == '}' || x == ']') {
            sta[top--];
        }
    }
};

int main() {
    SingleBalenced s;
    for (int i = 0; i < s.size; i++) {
        s.pushPop(s.exp[i]);
    }
    if (s.isEmpty()) {
        cout << "Valid Expression!";
    }
    else cout << "Invalid!";
}