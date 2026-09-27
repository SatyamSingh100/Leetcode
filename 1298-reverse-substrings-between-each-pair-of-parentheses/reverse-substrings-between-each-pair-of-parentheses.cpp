class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(res.size());
            }
            else if(s[i] == ')'){
                int k = st.top();
                reverse(res.begin() + k, res.end());
                st.pop();
            }
            else res += s[i];
        }
        return res;
    }
};