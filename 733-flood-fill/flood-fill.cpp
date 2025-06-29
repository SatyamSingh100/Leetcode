class Solution {
    private:
    void  bfs(int row,int col, vector<vector<int>>& a,int color,int ini,vector<vector<int>>& ans,int sr,int sc){
        int m = a.size(),n = a[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int delr[] ={-1,0,0,1};
        int delc[] ={0,-1,1,0};
        ans[sr][sc] = color;
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = r + delr[i], ncol = c + delc[i];
                if(nrow>= 0 && nrow < m && ncol >=0 && ncol < n && ans[nrow][ncol] != color && a[nrow][ncol] == ini){
                ans[nrow][ncol] = color; q.push({nrow,ncol});
            }
        }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        int ini = a[sr][sc];
        vector<vector<int>> ans = a;
        int m = a.size(),n=a[0].size();
        // int ini = a[sr][sc];
        bfs(sr,sc,a,color,ini,ans,sr,sc);
        return ans;
    }
};