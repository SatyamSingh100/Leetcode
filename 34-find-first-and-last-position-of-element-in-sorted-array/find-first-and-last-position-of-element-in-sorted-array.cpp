class Solution {
public:
    vector<int> searchRange(vector<int>& a, int tar) {
        int n = a.size(),first = -1, last =-1;
        int i=0,j=n-1;
        while(i <= j){
            int mid = (j-i)/2 + i;
            if(a[mid] == tar){
                first = mid;
                j = mid-1;
            }
            else if(a[mid] > tar) j = mid - 1;
            else i = mid + 1;
        }
        i = 0; j = n-1;
        while(i <= j){
            int mid = (j-i)/2 + i;
            if(a[mid] == tar){
                last = mid;
                i = mid+1;
            }
            else if(a[mid] > tar) j = mid - 1;
            else i = mid + 1;
        }
        vector<int> ans = {first,last};
        return ans;
    }
};