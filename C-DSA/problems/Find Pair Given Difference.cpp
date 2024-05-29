class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        // Bubble Sort implementation to sort the array
        sort(arr.begin(), arr.end());
        // Two-pointer technique to find the pair with the given difference
        int start = 0;
        int end = 1;

        while (start < n && end < n) {
            if (arr[end] - arr[start] == x && start != end) {
                return 1; // Pair found
            } else if (arr[end] - arr[start] < x) {
                end++;
            } else {
                start++;
            }
        }

        return -1; // No such pair found
    }
}