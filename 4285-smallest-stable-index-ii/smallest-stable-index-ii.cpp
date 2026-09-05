class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = nums[0];
        vector<int> minv(n,1e9);
        minv[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            minv[i] = min(minv[i+1], nums[i]);
        }
        
        for(int i=0; i<n; i++){
            int max_i = max(maxi,nums[i]);
            maxi = max(maxi,max_i);
            int min_i = minv[i];
            int score = max_i - min_i;
            if(score <= k) return i;
        }
        return -1;
    }
};