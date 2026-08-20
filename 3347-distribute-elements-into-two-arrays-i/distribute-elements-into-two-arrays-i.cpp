class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans,a1,a2;
        int n = nums.size();
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2; i<n; i++){
            if(a1[a1.size()-1] > a2[a2.size()-1]) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }
        int i=0;
        while(i<a1.size()){
            ans.push_back(a1[i]); i++;
        }
        i = 0;
        while(i < a2.size()){
            ans.push_back(a2[i]); i++;
        }
        return ans;
        
    }
};