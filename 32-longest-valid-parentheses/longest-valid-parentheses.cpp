class Solution {
public:
    int lefttoright(string s){
        int n = s.size(),open=0,close=0,ans=0;
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open += 1;
            else close += 1;
            if(open == close) ans = max(ans, open+close);
            else if(open < close){
                open =0; close =0;
            }
        }
        return ans;
    }
    int righttoleft(string s){
        int n = s.size(), open = 0, close =0,ans=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ')') close += 1;
            else open++;
            if(open == close) ans = max(ans, open + close);
            else if(open > close){
                open = 0; close =0;
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        int ans1 = lefttoright(s);
        int ans2 = righttoleft(s);
    
        return max(ans1,ans2);
    }
};