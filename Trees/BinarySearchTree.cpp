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

bool search(int x) {
    BST *p = root;
    while (p -> id != x && p != NULL) {
        if (x > p -> id) {
            p = p -> right;
        }
        else {
            p = p -> left;
        }
    }
    if (p != NULL) {
        return true;
    }
    else {
        return false;
    }
}


void deletion(int x) {
    BST *p = root, *k = NULL;
    while (p -> id != x && p != NULL) {
        k = p;
        if (x > p -> id)
            p = p -> right;
        else p = p -> left;
    }

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
        if (p -> left == NULL) {
            if (k -> right != NULL && p -> right != NULL) {
                k -> right = p -> right;
                delete p;
            }
            else if (k -> left != NULL && p -> right != NULL){
                k -> left = p -> right;
                cout << "P -->" << p -> id << endl;
                cout << "k -->"<< k -> id << endl;
                delete p;
            }
        }
        else {
            if (k -> left != NULL && p -> left != NULL) {
                k -> left = p -> left;
                delete p;
            }
            else if (k -> right != NULL && p -> left != NULL){
                k -> right = p -> left;
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
            if (p -> right != NULL) {
                d -> left = NULL;
                delete q;
            }
            else {
                p -> right = NULL;
                delete q;
            }
            //p -> right = NULL;
            //delete q;
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
    for (int i = 0; i < 12; i++) {
        insert();
    }
    int x, y;
    cout << "\nEnter a value to search: ";
    cin >> x;
    //BST *a = search(x);
    bool a = search(x);
    if (a == true) {
        cout << "\nValue found!";
    }
    else {
        cout << "\nValue not found!";
    }
    cout << endl;
    PreOrder(root);
    //for (int i = 0; i < 15; i++) {
        cout << "\nEnter a value to del: ";
        cin >> y;
        deletion(y);
        PreOrder(root);
    //}
}