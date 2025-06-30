class Solution {
public:
    bool bfs(int node, int color, vector<int>& vis, vector<vector<int>>& adj){
        queue<int> q;
        q.push(node);
        vis[node] = color;
        while(!q.empty()){
            int node = q.front();
            // color = 1 - color;
            q.pop();
            for(auto it: adj[node]){
                if(vis[it] == -1){
                    vis[it] = !vis[node];
                    q.push(it);
                }
                else if(vis[it] == vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
               if(bfs(i,0,vis,adj) == false) return false;
            }
        }
        return true;
    }
};