#include <iostream>
using namespace std;

void cyclicSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int correct = arr[i] - 1;
        if (arr[correct] != arr[i]) {
            swap(arr[i], arr[correct]);
        } else {
            i++;
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int arr[] = {1, 5, 8, 6, 9, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cyclicSort(arr, n);

    cout << "After sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
