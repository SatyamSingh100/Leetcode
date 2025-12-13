class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int l = 0, r = m -1;
        vector<int> ans(2,0);
        if(n == 1 && m == 1) return ans;
        while(l <= r){
            int mid = (l+r)/2;
            int row = 0,maxi = -1;
            for(int i=0; i<n; i++){
                if(a[i][mid] > maxi){
                    row = i;  maxi = a[row][mid];
                }
            }
            if((mid == m-1 && a[row][mid] > a[row][mid-1]) || (mid == 0 && a[row][mid] > a[row][mid+1]) || (mid != 0 && mid != m-1 && a[row][mid] > a[row][mid-1] && a[row][mid] > a[row][mid+1])){
                ans[0] = row; ans[1] = mid; 
                return ans;
            }
            else if((mid == m-1) || (mid != 0 && a[row][mid] < a[row][mid-1])) r = mid-1;
            else l = mid + 1;
        }
        return ans;
    }
};