class Solution {
public:
    bool isPal(string& s){
        int n = s.size();
        int i =0, j = n-1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void f(string& s,vector<string>& a, int idx, vector<vector<string>>& ans){
        int n = s.size();
        if(idx >= n){
            ans.push_back(a);
            return;
        }

        for(int j=idx; j<n; j++){
            string s1 = "";
            for(int i =idx; i<=j; i++) s1 += s[i];
            if(isPal(s1)){
                a.push_back(s1);
                f(s,a,j+1,ans);
                a.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a;
        f(s,a,0,ans);
        return ans;
    }
};