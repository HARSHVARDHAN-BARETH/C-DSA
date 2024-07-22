class Solution {
public:
    vector<int> prev_smaller(vector<int>& hights)
    {
        vector<int> ans;
        stack<int> st;
        int n = hights.size();
        
        for(int i=0;i<n;i++)
        {
            while(st.empty() == false && hights[st.top()]>=hights[i])
            {
                st.pop();
            }
            int res = (st.empty())?-1:st.top();
            ans.push_back(res);
            st.push(i);
        }
        return ans;
    }
    
        vector<int> next_smaller(vector<int>& hights)
    {
        vector<int> ans;
        stack<int> st;
        int n = hights.size();
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty() == false && hights[st.top()]>=hights[i])
            {
                st.pop();
            }
            int res = (st.empty())?n:st.top();
            ans.push_back(res);
            st.push(i);
        }
            reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> ps = prev_smaller(heights);
        vector<int> ns = next_smaller(heights);
        int n = heights.size();
        
        for(int i=0;i<n;i++)
        {
            int curr = (ns[i]-ps[i]-1)*heights[i];
            res = max(res, curr);
        }
        return res;
    }
};