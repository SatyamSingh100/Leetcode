class Solution {
public:
    int minimumPrefixLength(vector<int>& a) {
        int n = a.size(),ans=0;
        for(int i=0; i<n-1; i++){
            if(a[i] < a[i+1]) continue;
            else ans = max(ans,i+1);
        }
        return ans;
    }
};