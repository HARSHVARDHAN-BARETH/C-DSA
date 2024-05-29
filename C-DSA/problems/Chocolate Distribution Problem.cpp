class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
  sort(a.begin(), a.end());
    
    // Initialize the minimum difference to a large value
    long long minDiff = LLONG_MAX;
    
    // Iterate through the array and find the minimum difference
    for (long long i = 0; i + m - 1 < n; i++) {
        long long diff = a[i + m - 1] - a[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    
    return minDiff;
  }   
};