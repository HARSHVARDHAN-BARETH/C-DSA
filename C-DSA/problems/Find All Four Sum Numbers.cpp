To solve this problem, we need to find all unique quadruples in the array that sum up to a given number \( K \). Here’s a step-by-step explanation of how we can achieve this in C++:

1. **Sort the Array**: Sorting helps in easily skipping duplicates and also makes it easier to use two pointers to find pairs that sum up to a specific value.
2. **Iterate Over Pairs**: Use two nested loops to fix the first two elements of the quadruple.
3. **Two-Pointer Technique**: For the remaining two elements, use the two-pointer technique to find pairs that sum up to the required value.
4. **Skip Duplicates**: Ensure to skip duplicate elements to avoid repeated quadruples.

Here's the complete implementation:

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    std::vector<std::vector<int>> fourSum(std::vector<int>& arr, int k) {
        std::vector<std::vector<int>> result;
        int n = arr.size();
        
        if (n < 4) return result;
        
        // Sort the array to make it easier to skip duplicates and use two pointers
        std::sort(arr.begin(), arr.end());
        
        // Iterate over the array with two nested loops for the first two numbers
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    int sum = arr[i] + arr[j] + arr[left] + arr[right];
                    
                    if (sum == k) {
                        result.push_back({arr[i], arr[j], arr[left], arr[right]});
                        
                        // Move left pointer to the right, skipping duplicates
                        while (left < right && arr[left] == arr[left + 1]) ++left;
                        ++left;
                        
                        // Move right pointer to the left, skipping duplicates
                        while (left < right && arr[right] == arr[right - 1]) --right;
                        --right;
                    } else if (sum < k) {
                        ++left; // Need a larger sum, move left pointer to the right
                    } else {
                        --right; // Need a smaller sum, move right pointer to the left
                    }
                }
            }
        }
        
        return result;
    }
};
```

### Explanation of the Code:
1. **Sorting**: We first sort the array to facilitate the two-pointer approach and easy duplicate skipping.
2. **Outer Loops**: We use two nested loops to fix the first two elements of the quadruple.
3. **Two-Pointer Approach**: For the remaining two elements, we use the two-pointer technique. 
   - If the sum of the four elements equals \( K \), we add the quadruple to the result.
   - If the sum is less than \( K \), we need a larger sum, so we move the left pointer to the right.
   - If the sum is greater than \( K \), we need a smaller sum, so we move the right pointer to the left.
4. **Skipping Duplicates**: To ensure the uniqueness of quadruples, we skip duplicate values for both the fixed elements (first and second elements) and the moving elements (third and fourth elements).

This approach ensures that we find all unique quadruples that sum up to \( K \) efficiently.