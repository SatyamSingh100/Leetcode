class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n= a.size();
        long long cnt=0,ans=0;
        int maxi =0;
        for(int i=0; i<n; i++) maxi = max(maxi,a[i]);
        int i=0,j=0;
        while(j<n){
            if(a[j] == maxi) cnt++;
            // if(cnt == k) ans += (n-j);

            while(i<=j && cnt >= k){
                ans += (n-j);
                if(a[i] == maxi) cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};