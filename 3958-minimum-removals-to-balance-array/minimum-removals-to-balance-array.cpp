class Solution {
public:
    int minRemoval(vector<int>& a, int val) {
        int n = a.size(),cnt=1e9;
        sort(a.begin(),a.end());
        if(n == 1) return 0;
    
        for(int i=0; i<n-1; i++){
            int j = i+1, k = n-1,ans=i;
            while(j <= k){
                int mid = (j+k)/2;
                long long num = (long long)a[i]*val;
                if(a[mid] > num) k = mid-1;
                else{
                    ans = mid;
                    j = mid+1;
                }
            }
            cnt = min(cnt,(n+i-(ans+1)));
        }
        if(cnt == 1e9) cnt=1;
        return cnt;
    }
};