class Solution {
public:
    long long maxSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        long long ans=-1e18;
        vector<long long> pre(n+1,0);
        pre[0] = 0;
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + a[i];
        }

        for(int i=0; i<k; i++){
            long long curr = 0;
            for(int j=i; j<n; j+=k){
                int l = j+k-1;
                if(l < n){
                long long sum = pre[l+1] - pre[j];
                curr = max(sum,curr+sum);
                ans = max(ans,curr);
                }
            }
        }
        return ans;
    }
};