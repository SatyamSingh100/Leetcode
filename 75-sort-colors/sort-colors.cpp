class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch National Flag Algo.. (DNF Algo)
        int n = nums.size();
        int l=0,m=0,h=n-1;
        while(m<=h){
            if(nums[m] == 0) swap(nums[m],nums[l]), l++, m++;
            else if(nums[m] == 1) m++;
            else swap(nums[m],nums[h]), h--;
        }
        for(auto it:nums) cout<<it<<" ";


        //..Bubble Sort
        // int n = nums.size();
        // for(int i=0; i<n-1; i++){
        //     for(int j=0; j<n-i-1; j++){
        //         if(nums[j] > nums[j+1]) swap(nums[j],nums[j+1]);
        //     }
        // }
        // for(auto it:nums) cout<<it<<" ";
    }
};