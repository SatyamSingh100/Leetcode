class Solution {
public:
    bool carPooling(vector<vector<int>>& a, int k) {
        int n = a.size();
        vector<int> ans(1001,0);
        for(int i=0; i<n; i++){
            int st = a[i][1], end = a[i][2];
            ans[st] += a[i][0];
            ans[end] -= a[i][0];
        }
        for(int i=1; i<= 1000; i++) ans[i] = ans[i] + ans[i-1];
        for(auto it: ans){
            if(it > k) return false;
        }
        return true;
    }
};