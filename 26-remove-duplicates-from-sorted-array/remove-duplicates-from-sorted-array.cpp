class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0,  j = i+1,count=1;
        while(j < n){
            while(j < n && nums[i] == nums[j]) j++;
            if(j<n){
            swap(nums[i+1], nums[j]);
            i++; j++; count++;}
        }
        return count;
    }
};