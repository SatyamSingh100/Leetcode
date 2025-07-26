class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size(),i=0,j=n-1,ans=1e9;
        if(n == 1) return a[0];
        while(i <= j){
            int mid = (j-i)/2 + i;
            if(a[i] <= a[mid]){
                ans = min(ans,a[i]);
                i = mid + 1;
            }
            else{
                ans = min(ans,a[mid]);
                j = mid - 1;
            }
        }
        return ans;
    }
};