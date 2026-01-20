class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            // int num = a[i];
            for(int j=0; j<a[i]; j++){
                if((j | (j+1)) == a[i]) ans[i] = j;
                if(ans[i] != -1) break;
            }
        }
        return ans;
    }
};