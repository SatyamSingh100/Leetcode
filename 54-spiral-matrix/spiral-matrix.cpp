class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m=a.size(),n = a[0].size();
        int sr=0,er=m-1,sc=0,ec=n-1;
        vector<int> ans;
        while(sr<=er && sc<=ec){
            for(int j=sc; j<=ec; j++) ans.push_back(a[sr][j]);
            sr++;
            for(int i=sr; i<=er; i++) ans.push_back(a[i][ec]);
            ec--;
            if(sr <= er){
            for(int j=ec; j>=sc; j--) ans.push_back(a[er][j]);
            er--; 
            }
            if(sc <= ec){
            for(int i=er; i>=sr; i--) ans.push_back(a[i][sc]);
            sc++; 
            }
        }
        return ans;
    }
};