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

    bool isOperator(char inp) {
        if (inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == '^' || inp == '(') {
            return true;
        }
        else return false;
    }

    int inputPrec(char inp) {
        if (inp == '+' || inp == '-') {
            return 2;
        }
        else if (inp == '*' || inp == '/') {
            return 4;
        }
        else if (inp == '^') {
            return 6;
        }
        else return 0;
    }

    int stackPrec(char inp) {
        if (inp == '+' || inp == '-') {
            return 1;
        }
        else if (inp == '*' || inp == '/') {
            return 3;
        }
        else if (inp == '^') {
            return 7;
        }
        else return 10;
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
                else if (stackPrec(exp[i]) > inputPrec(sta[top])) {
                    sta[++top] = exp[i];
                }
                else {
                    cout << sta[top--];
                    while (stackPrec(exp[i]) < inputPrec(sta[top])) {
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

