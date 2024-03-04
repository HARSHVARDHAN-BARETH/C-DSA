#include <iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main()
{
     unordered_set<int> s;
     s.insert(1);
     s.insert(2);
     s.insert(3);
     s.insert(4);
     s.insert(5);
     
     for(auto it = s.begin(); it!=s.end(); it++)
     {
         cout << (*it) << endl;
     }
     
     cout << "number of element : " << s.size() <<  endl;
     
    //  s.clear();
     
    //   cout << "number of element : " << s.size() <<  endl;

     int key = 2;
     if(s.find(key) == s.end())
     {
         cout << "Key is not found" << endl;
     }
     else
     {
         cout << "Key is present" << endl;
     }
     
      if(s.count(5))
      {
          cout << "Yes " << endl;
      }
      else
      {
          cout << " Not " << endl;
      }
    
     
    return 0;
}
