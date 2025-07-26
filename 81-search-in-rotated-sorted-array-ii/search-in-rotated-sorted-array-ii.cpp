class Solution {
public:
    bool search(vector<int>& a, int tar) {
        int n = a.size(),i=0,j=n-1;
        while(i <= j){
            int mid = (j-i)/2 + i;
            if(a[mid] == tar) return true;
            else if(a[i] == a[mid] && a[j] == a[mid]){
                i++; j--;
            }
            else if(a[i] <= a[mid]){
                if(tar >= a[i] && tar <= a[mid]) j = mid - 1;
                else i = mid + 1;
            }
            else{
                if(tar >= a[mid] && tar <= a[j]) i = mid + 1;
                else j = mid -1;
            }
        }
        return false;
    }
};