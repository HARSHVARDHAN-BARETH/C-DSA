#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> umap;
    umap["aa"] = 44;
    umap["bb"] = 54;
    umap["cc"] = 65;
    
    // for(auto x:umap)
    // {
    //     cout << x.first << " " << x.second <<  endl;
    // }

    for(auto it = umap.begin(); it!= umap.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    string key = "aa";
    if(umap.find(key) != umap.end())
    {
        cout << "Keyy found" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    
    if(umap.find(key) != umap.end())
    {
        auto temp = umap.find(key);
        cout << "Key is " << temp->first << endl;
        cout << "Value is " << temp->second << endl;
    }
    return 0;
}
