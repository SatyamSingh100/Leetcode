class Solution {
public:
    string reverseParentheses(string s) {
        // string res = "";   // Stores our Result Array
        // stack<int> st;     // Stack to store how many chars of RES to SKIP before reversing
        // int n = s.size();
        // for(int i=0; i<n; i++){
        //     if(s[i] == '('){
        //         st.push(res.size());
        //     }
        //     else if(s[i] == ')'){
        //         int k = st.top();
        //         reverse(res.begin() + k, res.end());
        //         st.pop();
        //     }
        //     else res += s[i];
        // }
        // return res;

        // Wormhole Teleportation Technique
        int n = s.size();
        stack<int> st;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int j = st.top(); st.pop();
                a[i] = j; a[j] = i;
            }
        }

        int flag = 1;
        string res = "";
        for(int i=0; i<n; i+=flag){
            if(s[i] == '(' || s[i] == ')'){
                flag = -flag;
                i = a[i];
            }
            else res += s[i];
        }
        return res;
    }
};