#include <iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i =0;i<n;i++){
        sum += a[i];
    }
    if(sum > 0){cout<<"extra police"<<sum<<endl;}
    else if(sum < 0){cout<<"remaining crime "<<sum * -1<<endl;}
    else{cout<<"no crime";}
    return 0;
}