class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l =0, r = n-1;
        if(n == 1) return 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(mid == 0){
                if(a[mid] > a[mid+1]) return mid;
                else l = mid + 1;
            }
            else if(mid == n-1){
                if(a[mid] > a[mid-1]) return mid;
                else r = mid - 1;
            }
            else if((a[mid] > a[mid-1] && a[mid] > a[mid+1])) return mid;
            else if(a[mid] > a[mid-1] && a[mid] < a[mid+1]) l = mid + 1;
            else r = mid - 1; 
        }
        return -1;
    }
};