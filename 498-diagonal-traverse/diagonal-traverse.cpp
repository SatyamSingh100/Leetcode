class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int m = a.size(), n = a[0].size();
        int x =0, y=0, lim = (m+n-1),cnt=0;
        bool curr = true;
        while(cnt < lim){
            if(curr){
                int i = cnt, j = 0;
                while(i >= m){
                    i--; j++;
                }
                while(i >= 0 && j >= 0 && i < m && j < n){
                    ans.push_back(a[i][j]); i--; j++;
                }
            }
            else{
                int i =0, j = cnt;
                while(j >= n){
                    i++; j--;
                }
                while(i >=0 && j>=0 && i < m && j < n){
                    ans.push_back(a[i][j]); i++; j--;
                }
            }
            curr = !curr; cnt++;
        }
        return ans;
    }
};