#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class MultipleBalenced {
    public:
    string exp;
    char *sta;
    int top;
    int size;

    MultipleBalenced() {
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
        else if (x == ')' && sta[top] == '(') {
            sta[top--];
        }
        else if (x == '}' && sta[top] == '{') {
            sta[top--];
        }
        else if (x == ']' && sta[top] == '[') {
            sta[top--];
        }
    }
};

int main() {
    MultipleBalenced m;
        for (int i = 0; i < m.size; i++) {
            if ((m.sta[m.top] == '(') && (m.exp[i] == '{' || m.exp[i] == '[')) {
                cout << "\nAgainst priority order. ";
                break;
            } 
            else if (m.sta[m.top] == '{' && m.exp[i] == '[') {
                cout << "\nAgainst priority order. ";
                break;
            }
            else if ((m.exp[i] == ')' || m.exp[i] == '}' || m.exp[i] == ']') && (m.isEmpty())) {
                m.top = 100;
                break;
            }
            else {
                m.pushPop(m.exp[i]);
            }
        }
        if (m.isEmpty()) {
            cout << "Valid Expression!";
        }
        else cout << "Invalid Expression!";
    }