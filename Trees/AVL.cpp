#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct BST {
    int id;
    int bf = 0;
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

int count = 0, index = -1;
int size = 30;
int *arr;
arr = new int[size];

int leftSubTree(BST *p) {
    if (p != NULL) {
        count++;
        leftSubTree(p -> left);
        arr[++index] = count;
        count--;
        leftSubTree(p -> right);
    }
    int largest = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int count1 = 0, index1 = -1;
int *arr1;
arr1 = new int[size];

int rightSubTree(BST *q) {
    if (q != NULL) {
        count1++;
        rightSubTree(q -> right);
        arr1[++index1] = count1;
        count1--;
        rightSubTree(q -> left);
    }
    int large = arr1[0];
    for (int i = 0; i < size; i++) {
        if (arr1[i] > large) {
            large = arr1[i];
        }
    }
    return large;
}

void balencing(BST *k) {
    if (k != NULL) {
        balencing(k -> left);
        int leftH = leftSubTree(k -> left);
        int rightH = rightSubTree(k -> right);
        k -> bf = leftH - rightH;
        balencing(k -> right);
    }
}