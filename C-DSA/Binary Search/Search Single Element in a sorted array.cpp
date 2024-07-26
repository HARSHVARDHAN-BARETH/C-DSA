#include <iostream>
#include<vector>
using namespace std;

int SingleDuplicateElement(vector<int>& arr, int n)
{
    if(n == 1) return arr[0];
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(arr[i] != arr[i+1])
            {
                return arr[i];
            }
        }
        else if(i == n-1)
        {
            if(arr[i] != arr[i-1])
            {
                return arr[i];
            }
        }
        else if(arr[i] != arr[i-1] && arr[i] != arr[i+1])
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> arr  = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int n = arr.size();
    int ans = SingleDuplicateElement(arr, n);
    cout << "Single Element prsent  " << ans << " ";

    return 0;
}