class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(),ans=0;
        for(int i=0; i<n; i++){
            unordered_map<int,int> m;
            for(int j=i; j<n; j++){
                if(m.find(nums[j]) == m.end()) m[nums[j]] = 1;
                else m[nums[j]]++;
                ans += pow(m.size(), 2);
            }
        }
        return ans;
    }
};