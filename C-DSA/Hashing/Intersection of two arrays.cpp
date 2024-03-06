class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
       
       unordered_set<int>u;
       for(int i=0;i<n;i++)
       {
           u.insert(a[i]);
       }
       
       int count = 0;
       for(int i=0;i<m;i++)
       {
           int key = b[i];
           if(u.find(key) != u.end())
           {
               count++;
               u.erase(key);
           }
       }
       return count;
    }
};