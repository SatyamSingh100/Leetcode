class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& a) {
        int n = a.size();
        vector<int> ans(s.size()+1,0);
        for(int i=0; i<n; i++){
            int st = a[i][0], end = a[i][1];
            if(a[i][2] == 0){
                ans[st] += -1;
                ans[end+1] += 1;
            }
            else{
                ans[st] += 1;
                ans[end+1] += -1;
            }
        }
        for(int i=1; i<ans.size(); i++) ans[i] = ans[i] + ans[i-1];
        for(int i=0; i<s.size(); i++){
            ans[i] = ans[i] % 26;
            if(s[i] + ans[i] < 97) s[i] += ans[i] + 26;
            else if(s[i] + ans[i] > 122) s[i] += ans[i] - 26;
            else s[i] += ans[i];
        }
        return s;
    }
};