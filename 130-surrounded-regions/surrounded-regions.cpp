class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>& vis, vector<vector<char>>& a){
        vis[row][col] = 1;
        int deli[] = {-1,0,0,1};
        int delj[] = {0,-1,1,0};
        int m = a.size(), n = a[0].size();
        for(int i=0; i<4; i++){
            int nrow = row + deli[i], ncol = col + delj[i];
            if(nrow >= 0 && nrow <m && ncol >=0 && ncol < n && !vis[nrow][ncol] && a[nrow][ncol] == 'O')        {
                dfs(nrow,ncol,vis,a);
            }
        }
    }
    void solve(vector<vector<char>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int j=0; j<n; j++){
            if(a[0][j] == 'O' && !vis[0][j]) dfs(0,j,vis,a);
            if(a[m-1][j] == 'O' && !vis[m-1][j]) dfs(m-1,j,vis,a); 
        }
        
        for(int i=0; i<m; i++){
            if(a[i][0] == 'O' & !vis[i][0]) dfs(i,0,vis,a);
            if(a[i][n-1] == 'O' & !vis[i][n-1]) dfs(i,n-1,vis,a);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 'O' && !vis[i][j])  a[i][j] = 'X';
            }
        }
        
    }
};