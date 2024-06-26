#include <iostream>
using namespace std;

void rearange(int arr[], int n)
{
    int ans[n];
    int small = 0, largest = n-1;
    
    int flag = true;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            ans[i] = arr[largest--];
        }
        else
        {
            ans[i] = arr[small++];
        }
        flag = !flag;
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i] = ans[i];
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original Vaues " << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " \n";
    }

    rearange(arr, n);
       
    cout << "After Reanging  " << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    
    return 0;
}