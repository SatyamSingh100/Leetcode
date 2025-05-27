class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        for(int i=0; i<(1<<n); i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) v.push_back(a[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};