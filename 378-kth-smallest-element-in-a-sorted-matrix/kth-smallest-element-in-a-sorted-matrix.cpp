class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n= a.size();
        vector<int> v;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) v.push_back(a[i][j]);
        }
        sort(begin(v),end(v));
        return v[k-1];
    }
};