class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size(),l=0,r=n-1;
        if(n == 1) return a[0];
        while(l <= r){
            int mid = (l + r)/2;

            if((mid == 0 && a[mid] != a[mid+1]) || (mid == n-1 && a[mid] != a[mid-1]) ||((mid != 0) && (mid != n-1) && (a[mid] != a[mid-1] && a[mid] != a[mid+1]))|| (l == r && r == mid)) return a[mid];
            else if(l == mid && mid != r) return a[r];
            else if(r == mid && mid != l) return a[l];
            else if(a[mid] == a[mid-1]){
                if(mid & 1) l = mid+1;
                else r = mid-1;
            }
            else{
                if(mid & 1) r = mid-1;
                else l = mid+1;
            }
        }
        return -1;
    }
};