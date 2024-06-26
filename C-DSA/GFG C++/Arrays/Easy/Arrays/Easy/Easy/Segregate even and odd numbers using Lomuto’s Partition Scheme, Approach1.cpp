#include <iostream>
using namespace std;

void rearange(int arr[], int n)
{
    int ans[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] % 2 == 0)
        {
            ans[j++] = arr[i];
        }
    }
  
   for(int i=0;i<n;i++)
   {
       if(arr[i] % 2!=0)
        {
            ans[j++] = arr[i];
        }
   }
    
    for(int i=0;i<n;i++)
    {
        arr[i] = ans[i];
    }
    
}

int main()
{
    int arr[] = { 2,3,8,9,5,6,3,4,1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original Vaues " << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    rearange(arr, n);
       
    cout << "After Reanging  " << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    
    return 0;
}