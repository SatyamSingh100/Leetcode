class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& q) {
        int n = a.size(), m = q.size();
        vector<int> ans(m,0);
        sort(a.begin(),a.end());
        for(int i=0; i<n; i++){
            if(i == 0) a[i] = a[i];
            else a[i] = a[i] + a[i-1];
        }
        for(int i=0; i<m; i++){
            int num = upper_bound(a.begin(),a.end(),q[i]) - a.begin();
            ans[i] = num;
        }
        return ans;
    }
};