class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size(),l =0, r= n-1;
        if(n == 1) return a[0];
        if(a[0] != a[1]) return a[0];
        if(a[n-1] != a[n-2]) return a[n-1];
        while(l <= r){
            int mid = (l+r)/2;
            if((mid == 0 && a[mid] != a[mid+1]) || (mid == n-1 && a[mid] != a[mid-1]) || (a[mid] != a[mid-1] && a[mid] != a[mid+1])) return a[mid];
            else if(a[mid] == a[mid-1]){
                if(mid & 1) l = mid + 1;
                else r = mid -1;
            }
            else{
                if(mid & 1) r = mid-1;
                else l = mid +1;
            }
        }
        return -1;
    }
};