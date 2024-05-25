#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
    int repeating, missing;

    // Step 1: Find the repeating element by marking visited numbers
    for (int i = 0; i < n; ++i) {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0) {
            repeating = abs(arr[i]);
        } else {
            arr[index] = -arr[index];
        }
    }

    // Step 2: Find the missing element by checking which index is not marked
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
}

int main() {
    vector<int> arr = {2, 2}; // Example array
    int n = arr.size();

    vector<int> result = findTwoElement(arr, n);
    cout << "Repeating element: " << result[0] << ", Missing element: " << result[1] << endl;

    return 0;
}
