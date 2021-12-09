#include<iostream>
#include <queue>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

struct BST {
    int id;
    BST *right = NULL, *left = NULL;
};

BST *root = NULL, *current = NULL;


// int count = 0, index = -1;
// int size = 30;
// int arr[30] = {};

// int leftSubTree(BST *p) {
//     if (p != NULL) {
//         count++;
//         leftSubTree(p -> left);
//         arr[++index] = count;
//         count--;
//         leftSubTree(p -> right);
//     }
//     int largest = arr[0];
//     for (int i = 0; i < size; i++) {
//         if (arr[i] > largest) {
//             largest = arr[i];
//         }
//     }
//     // count = 0, index = -1;
//     // size = 30;
//     // arr[30] = {};
//     return largest;
// }

// int count1 = 0, index1 = -1;
// int arr1[30] = {};

// int rightSubTree(BST *q) {
//     if (q != NULL) {
//         count1++;
//         rightSubTree(q -> right);
//         arr1[++index1] = count1;
//         count1--;
//         if (q -> left == NULL) {
//             count1--;
//         }
//         rightSubTree(q -> left);
//     }
//     int large = arr1[0];
//     for (int i = 0; i < size; i++) {
//         if (arr1[i] > large) {
//             large = arr1[i];
//         }
//     }
//     // count1 = 0, index1 = -1;
//     // arr1[30] = {};
//     return large;
// }

// void balencing() {
//     BST *p = root;
//     BST *q = root -> left;
//     int leftH = leftSubTree(q -> left);
//     int rightH = leftSubTree(q -> right);
//     q -> bf = leftH - rightH;
//     cout << "Left: " << leftH << endl;
//     cout << "Right: " << rightH << endl;
//     cout << "Balencing: " << q -> bf << endl;
// }
// void insert() {
//     current = new BST;
//     cout << "\nEnter a value: ";
//     cin >> current -> id;
//     if (root == NULL) {
//         root = current;
//     }
//     else {
//         BST *p = root, *k = NULL;
//         while (p != NULL) {
//             k = p;
//             if (current -> id > p -> id) {
//                 p = p -> right;
//             }
//             else p = p -> left;
//         }
//         if (current -> id > k -> id) {
//             k -> right = current;
//         }
//         else k -> left = current;
//     }
// }

int height(BST *p) {
    if (p == NULL) {
        return -1;
    }
    int Lheight = height(p -> left);
    int Rheight = height(p -> right);
    return (max(Lheight, Rheight) + 1);
}

int getBalenceFactor(BST *p) {
    if (p == NULL) {
        return -1;
    }
    else {
        return (height(p -> left) - height(p -> right));
    }
}

BST *rightRotate(BST *p) {
    BST *q = p -> left;
    BST *k = q -> right;

    q -> right = p;
    p -> left = k;
    return q;
}

BST *leftRotate(BST *q) {
    BST *p = q -> right;
    BST *s = p -> left;

    p -> left = q;
    q -> right = s;
    return p;
}

BST *insert(BST *r, BST *current) {
    if (r == NULL) {
        r = current;
        return r;
    }
    else if (current -> id < r -> id) {
        r -> left = insert(r -> left, current);
    }
    else if (current -> id > r -> id) {
        r -> right = insert(r -> right, current);
    }

    int bf = getBalenceFactor(r);
    if (bf > 1 && current -> id < r -> left -> id) {
        return rightRotate(r);
    }
    else if (bf < -1 && current -> id > r -> right -> id) {
        return leftRotate(r);
    }
    else if (bf > 1 && current -> id > r -> left -> id) {
        r -> left = leftRotate(r -> left);
        return rightRotate(r);
    }
    else if (bf < -1 && current -> id < r -> right -> id) {
        r -> right = rightRotate(r -> right);
        return leftRotate(r);
    }
    return r;
}

void insertion() {
    current = new BST;
    cout << "\nEnter a value: ";
    cin >> current -> id;
    root = insert(root, current);
}

void PreOrder(BST *p) {
    if (p != NULL) {
        cout << p -> id << endl;
        PreOrder(p -> left);
        PreOrder(p -> right);
    }
}

int main() {
    int x;
    do {
        cout << "\n\t\tA V L\n";
        cout << "\nEnter 1 to insert \nEnter 2 to display \nEnter 3 for height "
                "\nEnter 0 to QUIT--> ";
        cin >> x;
        switch (x) {
            case 0:
                break;
            case 1:
                insertion();
                cout << "\nSuccessful!\n";
                break;
            case 2:
                PreOrder(root);
                break;
            case 3:
                cout << "BF of Root: " << getBalenceFactor(root) << endl;
                break;
        }
    } while(x != 0);
}

