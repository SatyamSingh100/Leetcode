class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> ans;
        for(int i=n-1; i>=0; i--){
            if(a[i] < 0) st.push(a[i]);
            else{
                while(!st.empty() && a[i] > abs(st.top())) st.pop();
                if(st.empty()) ans.push_back(a[i]);
                else{
                if(a[i] == abs(st.top())){
                    st.pop(); 
                }
                continue;
                }
            }
        }
        vector<int> c;
        while(!st.empty()){
            c.push_back(st.top());
            st.pop();
        }
        reverse(c.begin(),c.end());
        for(int i=0; i<c.size(); i++) ans.push_back(c[i]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};