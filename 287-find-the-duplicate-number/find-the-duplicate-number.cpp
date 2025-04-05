class Solution {
public:
    int findDuplicate(vector<int>& a) {
        // int fast=0;
        // int slow=0;
        // while(fast!=slow){
        //     fast = nums[nums[fast]];
        //     slow = nums[slow];
        // }
        // return fast;
        int n = a.size(),ans=-1;
        sort(begin(a),end(a));
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]){
                ans = a[i];
                break;
            }
        }
        return ans;
    }
};