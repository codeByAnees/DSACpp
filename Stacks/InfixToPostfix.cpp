#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Infix {
    public:
    string exp;
    int size;
    int top;
    char *sta;

    Infix() {
        cout << "Enter a infix expression: ";
        cin >> exp;
        size = exp.length();
        top = -1; 
        sta = new char[size];
    }

    int isOperator(char input) {
        switch (input) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 1;
        case '/':
            return 1;
        case '(':
            return 1;
        }
        return 0;
    }

    int inPrec(char input) {
        switch (input) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '(':
            return 0;
        }
    }

    int staPrec(char input) {
        switch (input) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '(':
            return 10;
        }
    }

    void converter() {
        for (int i = 0; i < size; i++) {
            if (exp[i] == ')') { 
                while (sta[top] != '(') {
                    cout << sta[top--];
                }
                sta[top--];
            }
            else if (isOperator(exp[i])) {
                if (exp[i] == '(') {
                    sta[++top] = exp[i];
                }
                else if (staPrec(exp[i]) > inPrec(sta[top])) {
                    sta[++top] = exp[i];
                }
                else {
                    cout << sta[top--];
                    while (staPrec(exp[i]) < inPrec(sta[top])) {
                        cout << sta[top--];
                    }
                    sta[++top] = exp[i];
                }
            }
            else cout << exp[i];
        }
        while (top >= 0) {
            cout << sta[top--];
        }
    }
};

int main() {
    Infix i;
    i.converter();
}

