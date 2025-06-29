class Solution {
private:
    void bfs(queue<vector<int>>& q,vector<vector<int>>& vis,vector<vector<int>>& a,int& maxi){
        int m = vis.size(), n = vis[0].size();
        int deli[] = {-1,0,0,1};
        int delj[] = {0,-1,1,0};
        while(!q.empty()){
            int r = q.front()[0],c= q.front()[1],curr = q.front()[2]; q.pop();
            for(int i=0; i<4; i++){
                int nrow = r + deli[i], ncol = c + delj[i],time = curr + 1;
                if(nrow>= 0 && nrow < m && ncol >=0 && ncol < n && vis[nrow][ncol] != 1 && a[nrow][ncol] == 1){
                vis[nrow][ncol] = 1; q.push({nrow,ncol,time});
                maxi = max(maxi,time);
            }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& a) {
        int m = a.size(),n = a[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 2){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }
        int maxi = 0;
        bfs(q,vis,a,maxi);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 0 && a[i][j] == 1) return -1;
            }
        }
        return maxi;
    }
};