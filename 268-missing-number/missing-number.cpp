class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),ans=0;
        vector<int> a(n+1,0);
        for(int i=1; i<=n; i++) a[i] = a[i-1] + 1;
        for(int i=0; i<n; i++) ans = ans ^ nums[i];
        for(int i=0; i<=n; i++) ans = ans ^ a[i];
        return ans;
    }
};