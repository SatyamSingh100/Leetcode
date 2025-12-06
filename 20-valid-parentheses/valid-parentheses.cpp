class Solution {
public:
    bool f(char x, char y){
        if((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')) return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty()){
                if((s[i] == ')') || (s[i] == ']') || (s[i] == '}')) return false;
                else st.push(s[i]);
            }
            else{
                if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) st.push(s[i]);
                else if(f(st.top(),s[i]) == true){
                    st.pop();
                }
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};