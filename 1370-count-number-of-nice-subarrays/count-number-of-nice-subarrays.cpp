class Solution {
public:
    int f(vector<int>& a, int k) {
        int n = a.size(),i=0,j=0,cnt=0,ans=0;
        if(k < 0) return 0;
        while(j < n){
            if(a[j] & 1) cnt++;
            while(cnt > k){
                if(a[i] & 1) cnt--;
                i++;
            }
            if(cnt <= k) ans += (j-i) + 1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = f(nums,k) - f(nums, k-1);
        return ans;
    }
};