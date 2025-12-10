class Solution {
public:
    bool f1(vector<int>& a, int h, int k){
        long long ans = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] % k == 0) ans += a[i]/k;
            else ans += (a[i]/k) + 1;
        }
        if(ans <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        int l = 1, r = *max_element(a.begin(),a.end());
        int ans = r;
        while(l <= r){
            int mid = (l + r)/2;
            if(f1(a,h,mid)){
                ans = min(ans,mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};