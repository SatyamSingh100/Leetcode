class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size(),l=0,r=n-1;
        if(n == 1) return 0;
        if(n == 2 && a[0] < a[1]) return 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(mid == l){
                if(a[l] > a[r]) return l;
                else return r;
            }
            else if(mid == r){
                if(a[l] > a[r]) return l;
                else return r;
            }
            else if((a[mid] > a[mid-1] && a[mid] > a[mid+1])) return mid;
            else if(a[mid] > a[mid-1]) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};