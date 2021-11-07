#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class Postfix {
    public:
    int top;
    string exp;
    int *sta;
    int size;
    Postfix() {
        cout << "Enter a postfix expression: ";
        cin >> exp;
        size = exp.length();
        sta = new int[size];
        top = -1;
    }
    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    void cal() {
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '-') {
                int y = sta[top--];
                int x = sta[top--];
                sta[++top] = x - y;
            }
            else if (exp[i] == '+') {
                int y = sta[top--];
                int x = sta[top--];
                sta[++top] = x + y;
            }
            else if (exp[i] == '*') {
                int y = sta[top--];
                int x = sta[top--];
                sta[++top] = x * y;
            }
            else if (exp[i] == '/') {
                int y = sta[top--];
                int x = sta[top--];
                sta[++top] = x / y;
            }
            else {
                char c = exp[i];
                int a = c - '0';
                sta[++top] = a;
            }
        }
        cout << "Ecaluated value: " << sta[top];
    }
};

int main() {
    Postfix p;
    p.cal();
}