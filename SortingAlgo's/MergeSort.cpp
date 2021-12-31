#include<iostream>
using namespace std;

class sort {
    public:
    int *arr;
    int size;

    sort() {
        int x;
        cout << "Enter length of list: ";
        cin >> x;
        size = x;
        arr = new int[size];
    }

    void mergesort(int list[], int first, int last) {
        int mid;
        if (first <= last) {
            mid = (first + last) / 2;
            mergesort(list, first, mid);
            mergesort(list, mid + 1, last);
            merge(list, first, mid, last);
        }
    }

    void merge(int list[], int first, int mid, int last) {
        int firstA = first;
        int lastA = mid;
        int firstB = mid + 1;
        int lastB = last;
        
        int index = firstA;
        int *tempArray;
        tempArray = new int[size];
        while (firstA <= lastA && firstB <= lastB) { 
            if (list[firstA] < list[firstB]) {
                tempArray[index] = list[firstA];
                firstA = firstA + 1;
            }
            else {
                tempArray[index] = list[firstB];
                firstB = firstB + 1;
            }
            index = index + 1;
        }
        while (firstA <= lastA) {
            tempArray[index] = list[firstA];
            firstA = firstA + 1;
            index = index + 1;
        }
        while (firstB <= lastB) {
            tempArray[index] = list[firstB];
            firstB = firstB + 1;
            index = index + 1;
        }

        index = first;
        while (index <= last) {
            list[index] = tempArray[index];
            index = index + 1;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    sort s;
    for (int i = 0; i < s.size; i++) {
        cout << "Enter a number: ";
        cin >> s.arr[i];
    }
    cout << "\nUnsorted: ";
    s.display();
    s.mergesort(s.arr, 0, s.size - 1);
    cout << "\n  Sorted: ";
    s.display();
}
