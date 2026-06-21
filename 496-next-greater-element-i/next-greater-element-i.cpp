class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size();
        stack<int> st;
        vector<int> ans(n,-1);
        st.push(b[0]);
        for(int i=1; i<b.size(); i++){
            st.push(b[i]);
        }
        for(int i=0; i<n; i++){
            stack<int> c = st;
            int maxi = -1;
            while(c.empty() == false){
                if(c.top() == a[i]){
                    ans[i] = maxi; break;
                }
                else{
                    if(c.top() > a[i]) maxi = c.top();
                    c.pop();
                }
            }
        }
        return ans;
    }
};