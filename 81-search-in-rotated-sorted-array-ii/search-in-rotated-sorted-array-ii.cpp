class Solution {
public:
    bool search(vector<int>& a, int tar) {
        int n = a.size(), i =0,j=n-1;
        while(i <= j){
            int mid = (i + j)/2;
            if(a[mid] == tar) return true;
            else if(a[mid] == a[i]){
                while(mid >= i && a[mid] == a[i]){
                    if(a[mid] == tar) return true;
                    mid--; i++;
                }
            }
            else if(a[mid] > a[i]){                            // Left Sorted
                if(tar >= a[i] && tar < a[mid]) j = mid - 1;
                else i = mid + 1;
            }
            else{
                if(tar > a[mid] && tar <= a[j]) i = mid + 1;
                else j = mid - 1;
            }
        }
        return false;
    }
};