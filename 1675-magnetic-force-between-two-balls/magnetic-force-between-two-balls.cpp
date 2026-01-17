class Solution {
public:
    int f(vector<int>& a, int mid){
        int n = a.size(),cnt=1,i=0;
        while(i < n){
            int num = a[i] + mid;
            i = lower_bound(a.begin(),a.end(),num) - a.begin();
            if(i < n) cnt++;
        }
        return cnt;
    }
    int maxDistance(vector<int>& a, int m) {
        int n = a.size(),ans=0;
        sort(a.begin(),a.end());
        int l = 1, r = a[n-1] - a[0];
        while(l <= r){
            int mid = (l + r)/2;
            int num = f(a,mid);
            if(num >= m){
                ans = mid; l = mid +1;
            }
            else r = mid -1;
        }
        return ans;
    }
};