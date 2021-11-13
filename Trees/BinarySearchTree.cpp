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
    cout << "Enter value: ";
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

BST *search(int x) {
    BST *p = root;
    while (p -> id != x && p != NULL) {
        if (x > p -> id)
            p = p -> right;
        else p = p -> left;
    }
    return p;
}

// BST *search1(int x) {
//     BST *p = root, *k = NULL;
//     while (p -> id != x && p != NULL) {
//         k = p;
//         if (x > p -> id)
//             p = p -> right;
//         else p = p -> left;
//     }
//     return k;
// }


void deletion(int x) {
    BST *p = root, *k = NULL;
    while (p -> id != x && p != NULL) {
        k = p;
        if (x > p -> id)
            p = p -> right;
        else p = p -> left;
    }
    // BST *p = search(x);
    // BST *k = search1(x);
    if (p -> right == NULL && p -> left == NULL) {
        if (k -> right == p) {
            k -> right = NULL;
            delete p;
        }
        else {
            k -> left = NULL;
            delete p;
        }
    }
    else if (p -> right == NULL || p -> left == NULL) {
        if (p -> right == NULL) {
            if (k -> left != NULL && p -> left != NULL) {
                k -> left = p -> left;
                delete p;
            }
            else {
                k -> right = p -> left;
                delete p;
            }
        }
        else {
            if (k -> right != NULL && p -> right != NULL) {
                k -> right = p -> right;
                delete p;
            }
            else {
                k -> left = p -> right;
                delete p;
            }
        }
    }
    else {
        BST *q = p -> right, *d = NULL;
        while (q -> left != NULL) {
            d = q;
            q = q -> left;
        }
        p -> id = q -> id;
        if (q -> right != NULL) {
            d -> left = q -> right;
            delete q;
        }
        else {
            d -> left = NULL;
            delete q;
        }
    }
}

void PreOrder(BST *p) {
    if (p != NULL) {
        cout << p -> id << " ";
        PreOrder(p -> left);
        PreOrder(p -> right);
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        insert();
    }
    int x, y;
    cout << "\nEnter a value to search: ";
    cin >> x;
    BST *a = search(x);
    if (a -> id == x)
        cout << "\nValue found!";
    else cout << "\nNo such value!";
    cout << endl;
    PreOrder(root);
    cout << "\nEnter a value to del: ";
    cin >> y;
    deletion(y);
    PreOrder(root);
}