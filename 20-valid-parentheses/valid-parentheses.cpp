class Solution {
public:
    bool check(char a, char b){
        if((a == '('&& b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int n = s.size(),i=0;
        if(n == 1) return false;
        stack<char> st;
        while(i < n){
            if( (s[i] == ')' || s[i] == ']' || s[i] == '}') ){
                if(st.empty()) return false;
                if(check(st.top(),s[i]) == false) return false;
                else if(check(st.top(),s[i])){ st.pop(); i++; }
                // else {st.push(s[i]); i++;}
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        if(st.empty() == false) return false;
        return true;
    }
};