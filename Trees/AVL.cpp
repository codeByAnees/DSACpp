#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct BST {
    int id;
    BST *right = NULL, *left = NULL;
};

BST *root = NULL, *current = NULL;

void insert() {
    current = new BST;
    cout << "\nEnter a value: ";
    cin >> current -> id;
    if (root == NULL) {
        root = current;
    }
    else {
        BST *p = root, *k = NULL;
        while (p != NULL) {
            k = p;
            if (current -> id > p -> id) {
                p = p -> right;
            }
            else p = p -> left;
        }
        if (current -> id > k -> id) {
            k -> right = current;
        }
        else k -> left = current;
    }
}