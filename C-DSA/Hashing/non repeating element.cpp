int firstNonRepeating(int arr[], int n) 
    { 
         unordered_map<int, int> umap;
         
         for(int i=0;i<n;i++)
         {
             umap[arr[i]]++;
         }
         
         for(int i=0;i<n;i++)
         {
             int key = arr[i];
             auto temp = umap.find(key);
             if(temp->second == 1)
             {
                 return key;
             }
         }
                     return 0;

    } 
