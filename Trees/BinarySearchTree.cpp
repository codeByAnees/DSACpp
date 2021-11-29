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

BST *search() {
    int x;
    cout << "\nEnter a value to search: ";
    cin >> x;
    BST *p = root;
    while (p -> id != x && p != NULL) {
        if (x > p -> id) {
            p = p -> right;
        }
        else {
            p = p -> left;
        }
        if (p == NULL) break;
    }
    return p;
}


void deletion(int x) {
    BST *p = root, *k = NULL;
    while (p -> id != x && p != NULL) {
        k = p;
        if (x > p -> id) {
            p = p -> right;
        }
        else p = p -> left;
    }
    if (p -> right == NULL && p -> left == NULL) {
        if (k -> right == p) {
            delete p;
            k -> right = NULL;
        }
        else {
            delete p;
            k -> left = NULL;
        }
    }
    else if (p -> right == NULL || p -> left == NULL) {
        if (p -> left == NULL) {
            if (k -> right == p && p -> right != NULL) {
                k -> right = p -> right;
                delete p;
            }
            else if (k -> left == p && p -> right != NULL) {
                k -> left = p -> right;
                delete p;
            }
        }
        else {
            if (k -> left == p && p -> left != NULL) {
                k -> left = p -> left;
                delete p;
            }
            else if (k -> right == p && p -> left != NULL) {
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
        if (q -> left == NULL) {
            if (q -> right == NULL) {
                p -> right = NULL;
                delete q;
            }
            else {
                p -> right = q -> right;
                delete q;
            }
        }
        else if (q -> right != NULL) {
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
    int x;
    do {
        cout << "\n\t\tBinary Search Tree\n";
        cout << "\nEnter 1 to insert \nEnter 2 to search \nEnter 3 to delete "
                "\nEnter 4 to display \nEnter 0 to QUIT--> ";
        cin >> x;
        switch (x) {
            case 0:
                break;
            case 1:
                insert();
                cout << "\nSuccessful!\n";
                break;
            case 2:
                BST *a;
                a = search();
                if (a != NULL) {
                    cout << "\nValue found!\n";
                }
                else cout << "\nValue not found!\n";
                break;
            case 3:
                int z;
                cout << endl;
                PreOrder(root);
                cout << endl;
                cout << "\nEnter a value to delete: ";
                cin >> z;
                deletion(z);
                cout << "\nSuccessful!\n";
                PreOrder(root);
                cout << endl;
                break;
            case 4:
                cout << endl;
                PreOrder(root);
                cout << endl;
                break;
            default:
                cout << "\nWrong input\n";
        }
    } while (x != 0);
}