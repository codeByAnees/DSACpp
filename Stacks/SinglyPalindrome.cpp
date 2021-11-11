// When I run this program on DEV-C++ or on VS Code it gives me error
// But when I run it on online compiler, it works as it should be.
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Node {
    char letter;
    Node *forward;
};

string word;
Node *top_1 = NULL, *tail_1 = NULL, *current = NULL;
Node *top_2 = NULL, *tail_2 = NULL;

void sta_1() {
    cout << "\n\t\tPalindrome Checker\n";
    cout << "Enter a word: ";
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        current = new Node;
        current -> letter = word[i];
        if (top_1 == NULL) {
            top_1 = tail_1 = current;
        }
        else {
            current -> forward = top_1;
            top_1 = current;
        }
    }
}

void sta_2() {
    Node *a = top_1;
    while (a != NULL) {
        current = new Node;
        current -> letter = a -> letter;
        if (top_2 == NULL) {
            top_2 = tail_2 = current;
        }
        else {
            current -> forward = top_2;
            top_2 = current;
        }
        a = a -> forward;
    }
}

bool check() {
    bool check = true;
    Node *a = top_1, *b = top_2;
    while (a != NULL) {
        if (a -> letter == b -> letter) {
            Node *c = a, *d = b;
            a = c -> forward;
            b = d -> forward;
            delete c, d;
        }
        else {
            check = false;
            break;
        }
    }
    return check;
}

int main() {
    sta_1();
    sta_2();
    bool ch = check();
    if (ch == true) cout << "YES, It's a PALINDROME";
    else cout << "Not a Palindrome";
}