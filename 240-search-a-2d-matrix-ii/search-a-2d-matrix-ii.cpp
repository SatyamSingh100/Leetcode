class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int tar) {
        int n = a.size(), m= a[0].size();
        int r = 0, c=  m-1;
        while(r < n && c >= 0){
            int num = a[r][c];
            if(num == tar) return true;
            else if(num > tar) c--;
            else r++;
        }
        return false;
    }
};