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
    MultipleBalenced s;
    for (int i = 0; i < s.size; i++) {
        if ((s.sta[s.top] == '(') && (s.exp[i] == '{' || s.exp[i] == '[')) {
            cout << "\nAgainst priority order. ";
            break;
        } 
        else if (s.sta[s.top] == '{' && s.exp[i] == '[') {
            cout << "\nAgainst priority order. ";
            break;
        }
        else s.pushPop(s.exp[i]);
    }
    if (s.isEmpty()) {
        cout << "Valid Expression!";
    }
    else cout << "Invalid!";
}