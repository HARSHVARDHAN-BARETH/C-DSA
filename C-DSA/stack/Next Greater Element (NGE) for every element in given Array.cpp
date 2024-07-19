#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n)
{
    stack<int> s;
    s.push(0); // Push index 0 initially
    
    for(int i = 1; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] < arr[i])
        {
            cout << arr[s.top()] << " -> " << arr[i] << endl;
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty())
    {
        cout << arr[s.top()] << " -> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);

    return 0;
}
