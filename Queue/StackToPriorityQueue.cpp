#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class myClass {
    public:
    int *sta1;
    int *sta2;
    int top1;
    int top2;
    myClass() {
        sta1 = new int[5];
        sta2 = new int[5];
        top1 = -1;
        top2 = -1;
    }

    void method(int x) {
        if (top1 == -1) {
            sta1[++top1] = x;
        }
        else {
            if (sta1[top1] > x && top1 == 0) {
                sta2[++top2] = sta1[top1--];
                sta1[++top1] = x;
                sta1[++top1] = sta2[top2--];
            }
            else if (sta1[top1] > x) {
                while (sta1[top1] < x || top1 != -1) {
                    sta2[++top2] = sta1[top1--];
                }
                sta1[++top1] = x;
                while (top2 != -1) {
                    sta1[++top1] = sta2[top2--];
                }
            }
            else {
                sta1[++top1] = x;
            }
        }
    }

    void display() {
        for (int i = top1; i >= 0; i--) {
            cout << sta1[i] << " ";
        }
    }
};

int main() {
    myClass m;
    int x;
    for (int i = 0; i < 5; i++) {
        cout << "Enter a value: ";
        cin >> x;
        m.method(x);
    }
    m.display();
}