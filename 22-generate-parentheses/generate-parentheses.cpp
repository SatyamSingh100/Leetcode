class Solution {
public:
    void f(string& s, int open, int close, int n, vector<string>& ans){
        if(open == 0 && close == 0){
            ans.push_back(s); return;
        }
        if(open < 0 || close < 0 || open > close) return;

        // if(open < close)
        s.push_back('(');
        f(s,open-1,close,n,ans);
        s.pop_back();

        if(s.size() > 0){
            s.push_back(')');
            f(s,open,close-1,n,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n,close =n;
        string s ="";
        vector<string> ans;
        f(s,open,close,n,ans);
        return ans;
    }
};