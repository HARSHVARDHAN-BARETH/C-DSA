#include <iostream>
#include<algorithm>
using namespace std;

int main()
{

   int a[10] = {5,1,2,3,6,4,5,8,9};
   sort(a, a+10);
   
   for(int i=0;i<10;i++)
   {
       cout << a[i] << " ";
   }
   cout << endl;

    return 0;
}
