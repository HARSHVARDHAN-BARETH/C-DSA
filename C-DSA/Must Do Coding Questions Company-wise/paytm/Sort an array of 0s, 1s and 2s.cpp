class Solution
{
    public:
   void sort012(int a[], int n) {
        // Vectors to store 0s, 1s, and 2s separately
       vector<int> zero;
       vector<int> one;
       vector<int> two;
      
        for(int i=0;i<n;i++)
        {
            if(a[i] == 0)
            {
                zero.push_back(a[i]);
            }else if(a[i] == 1)
            {
                one.push_back(a[i]);
            }else if(a[i] == 2)
            {
                two.push_back(a[i]);
            }
        }
        
        int index = 0;
        
        for(int i=0;i<zero.size();i++)
        {
            a[index++] = zero[i];
        }
        for(int i=0;i<one.size();i++)
        {
            a[index++] = one[i];
        }
        for(int i=0;i<two.size();i++)
        {
            a[index++] = two[i];
        }
      
   }
}