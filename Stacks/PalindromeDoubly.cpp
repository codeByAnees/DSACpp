#include<iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

struct node {
    char letter;
    node *next = NULL, *prev = NULL;
};

node *head = NULL, *top1 = NULL, *current = NULL;
node *start = NULL, *top2 = NULL;


void stack_1() {
    cout << "\n\t\tPalindrome Checker\n";
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for (int i = 0; i < word.length(); i++) {
        current = new node;
        current -> letter = word[i];
        if (head == NULL) {
            head = top1 = current;
        }
        else {
            top1 -> next = current;
            current -> prev = top1;
            top1 = current;
        }
    }
}

void stack_2() {
    node *a = top1;
    while (a != NULL) {
        current = new node;
        current -> letter = a -> letter;
        if (start == NULL) {
            start = top2 = current;
        }
        else {
            top2 -> next = current;
            current -> prev = top2;
            top2 = current;
        }
        a = a -> prev;
    }
}


bool checker() {
    bool check = true;
    node *a = top1, *b = top2;
    while (a != NULL) {
        if (a -> letter == b -> letter) {
            a = a -> prev;
            b = b -> prev;
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
    if (check == true)
        cout << "PALINDROME!";
    else cout << "Not PALINDROME";
}