class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n= a.size();
        int l = 0, r=n-1;
        while(l <= r){
            int mid =  (l+r)/2;
            if(mid == 0) return (a[0] > a[1] ? 0 : 1);
            else if(mid == n-1)  return (a[n-1] > a[n-2] ? n-1 : n-2);
            else if(a[mid] > a[mid-1] && a[mid] > a[mid+1]) return mid;
            else if(a[mid] > a[mid-1]) l = mid + 1;
            else r = mid -1;  
        }
        return -1;
    }
};