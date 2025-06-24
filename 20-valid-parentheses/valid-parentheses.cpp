class Solution {
public:

   bool isPair(char c,char p){
    if(c == '(') return p == ')';
    else if(c == '{') return p == '}';
    else if(c == '[') return p == ']';
    return false;
   }

    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(st.empty()) st.push(s[i]);
            else if(isPair(st.top(),s[i])) st.pop();
            else st.push(s[i]);
        }
        return st.empty() == true;
    }
};