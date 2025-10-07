class Solution {
public:
    bool search(vector<int>& a, int k) {
        int n = a.size();
        if(n == 1) return a[0] == k;
        int l = 0, r = n-1;
        while(l <= r){
            int mid =  l + (r-l)/2;
            if(a[mid] == k) return true;
            else if(a[mid] ==  a[l] && a[r] == a[mid]){
                l++; r--;
            }
            else if(a[mid] <= a[r]){
                if(k <= a[r] && k > a[mid]) l = mid + 1;
                else r = mid - 1;
            }
            else{
                if(k < a[mid] && k >= a[l]) r = mid - 1;
                else l = mid + 1;
            }
        }
        return false;
    }
};