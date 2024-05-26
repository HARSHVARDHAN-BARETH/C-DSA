include <algorithm> // For std::sort, std::max, and std::min
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        
        int diff = arr[n-1] - arr[0];
        int maxVal, minVal;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i] - k < 0) continue;
            maxVal = max(arr[i-1]+k, arr[n-1]-k);
            minVal = min(arr[0]+k, arr[i]-k);
            diff = min(diff, maxVal-minVal);
        }
        return diff;
    }
}