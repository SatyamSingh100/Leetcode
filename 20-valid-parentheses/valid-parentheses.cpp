class Solution {
public:
    bool check(char a, char b){
        if(b == ')') return a == '(';
        else if(b == ']') return a == '[';
        else if(b == '}') return a == '{';
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n & 1) return false;
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' ||  s[i] == '[') st.push(s[i]);
            else {
                if(st.empty()) return false;
                else{
                    if(check(st.top(),s[i])){
                        st.pop();
                    }
                    else return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};