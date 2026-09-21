class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(),ans=n+1;
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(num >= k){
                ans = 1; break;
            }
            for(int j=i+1; j<n; j++){
                num = num | nums[j];
                if(num >= k) {
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }
        if(ans == n+1) return -1;
        return ans;
    }
};