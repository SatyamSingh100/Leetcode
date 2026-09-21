class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(),cnt=0,ans=nums[0];
        for(int i=0; i<n; i++){
            if(nums[i] == ans) cnt++;
            else cnt--;
            if(cnt < 0){
                ans = nums[i]; cnt = 1;
            }
        }
        return ans;
    }
};