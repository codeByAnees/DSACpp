#include<iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

struct node {
    char letter;
    node *next;
};

node *top1 = NULL, *tail = NULL, *current = NULL;
node *top2 = NULL, *end = NULL;


void stack_1() {
    cout << "\n\t\tPalindrome Checker\n";
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        current = new node;
        current -> letter = word[i];
        if (top1 == NULL) {
            top1 = tail = current;
        }
        else {
            current -> next = top1;
            top1 = current;
        }
    }
}

void stack_2() {
    node *a = top1;
    while (a != NULL) {
        current = new node;
        current -> letter = a -> letter;
        if (top2 == NULL) {
            top2 = end = current;
        }
        else {
            current -> next = top2;
            top2 = current;
        }
        a = a -> next;
    }
}

bool checker() {
    bool check = true;
    node *a = top1, *b = top2;
    while (a != NULL) {
        if (a -> letter == b -> letter) {
            node *c = a;
            node *d = b;
            a = c -> next;
            b = d -> next;
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
    stack_1();
    stack_2();
    bool check = checker();
    if (check == true) {
        cout << "PALINDROME!";
    }
    else cout << "Not PALINDROME";
}