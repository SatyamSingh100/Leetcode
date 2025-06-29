class Solution {
private:
   void bfs(int node, vector<int>& vis, vector<int> adj[]){
    int n = vis.size();
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while(!q.empty()){
        int nod = q.front(); q.pop();
        for(auto it: adj[nod]){
            if(vis[it] == 0){
                vis[it] = 1; q.push(it);
            }
        }
    }
   }
    // void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& a,int delr[],int delc[]){
    //     int n = a.size();
    //     queue<pair<int,int>> q;
    //     q.push({row,col});
    //     vis[row][col] = 1;
    //     while(!q.empty()){
    //         int r = q.front().first, c = q.front().second;
    //         q.pop();
    //         for(int i=0; i<4; i++){
    //                 int nrow = r + delr[i], ncol = c + delc[i];
    //                 if(nrow>= 0 && nrow < n && ncol >=0 && ncol < n && vis[nrow][ncol] == 0 && a[nrow][ncol] == 1){
    //                     vis[nrow][ncol] = 1;
    //                     q.push({nrow,ncol});
    //                 }
    //             }
    //         }
    // }
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> adj[n];
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] == 1 && i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;

        // vector<vector<int>> vis(n,vector<int>(n,0));
        // int cnt =0;
        // int delr[] ={-1,0,0,1};
        // int delc[] ={0,-1,1,0};
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(vis[i][j] == 0 && a[i][j] == 1){
        //             bfs(i,j,vis,a,delr,delc);
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }
};