class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        for(int i=0; i<n-1; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int> a = {nums[i], nums[j], nums[k]};
                    s.insert(a);
                    j++; k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
        }
        vector<vector<int>> ans;
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};