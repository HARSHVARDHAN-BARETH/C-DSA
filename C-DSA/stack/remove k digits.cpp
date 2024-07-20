class Solution {
public:
    string removeKdigits(string num, int k) {
        // A stack to keep track of the digits for the smallest possible number
        stack<char> st;

        for (char digit : num) {
            // Remove digits from the stack if they are larger than the current digit
            // and we still have k digits to remove
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // Remove remaining k digits from the end of the stack if needed
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Collect the digits from the stack into a string in correct order
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }

        // Return the resulting string or "0" if it's empty
        string smallestNumber = result.substr(start);
        return smallestNumber.empty() ? "0" : smallestNumber;
    }
};
