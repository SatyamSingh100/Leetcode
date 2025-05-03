class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt=0,sum=0,n=nums.size();
        int i=0,j=0;
        while(j<n){
            sum += nums[j];

            while(i<=j && sum * (j-i+1) >= k){
                sum = sum - nums[i];
                i++;
            }

            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};