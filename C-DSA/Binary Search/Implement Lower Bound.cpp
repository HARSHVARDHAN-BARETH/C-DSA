#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> nums, int n, int x)
{
    int start = 0, end = n-1;
    int ans = n;
    
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(nums[mid] >= x)
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = binarySearch(nums, n, x);
    cout << "Lower bound is at " << ind << endl;

    return 0;
}