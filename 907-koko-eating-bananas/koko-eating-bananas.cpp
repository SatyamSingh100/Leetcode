class Solution {
public:
    bool isValid(vector<int> a, int r, int h){
        long long n = a.size(),sum=0,i=0;
        while(i < n){
            if(a[i] > r){
                sum += a[i]/r; a[i] = a[i] % r;
                if(a[i] == 0) i++;
            }
            else{
                sum++; i++;
            }
        }
        if(sum > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int l = 1,r=1,n = a.size(),ans = 0;
        for(int i=0; i<n; i++) r = max(a[i],r);
        while(l <= r){
            int mid = (l + r)/2;
            if(isValid(a,mid,h)){
                ans = mid; r = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};