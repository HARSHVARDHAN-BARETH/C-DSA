#include <iostream>
#include<vector>
using namespace std;

void rearange(int arr[], int n)
{
    vector<int> positive, negative;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            positive.push_back(arr[i]);
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }
    
    int posIndex = 0, negIndex = 0, arrIndex = 0;
    bool PositiveTurn = 1;
    while(posIndex < positive.size() && negIndex < negative.size())
    {
         if(PositiveTurn)
         {
             arr[arrIndex++] = positive[posIndex++];
         }
         else
         {
             arr[arrIndex++] = negative[negIndex++];
         }
         
         PositiveTurn = !PositiveTurn;
    }
    
    while(posIndex < positive.size())
    {
        arr[arrIndex++]  = positive[posIndex++];
    }
    
    while(negIndex < negative.size())
    {
        arr[arrIndex++] = negative[negIndex++];
    }
}

int main()
{
   int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
   int n = sizeof(arr)/sizeof(arr[0]);
   
   rearange(arr, n);
   
   for(int i=0;i<n;i++)
   {
       cout << arr[i] << " ";
   }
   
    return 0;
}