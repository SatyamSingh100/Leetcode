class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a, int k) {
        int n = a.size() , m = a[0].size();
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                a[i][j] = a[i][j] + a[i-1][j];
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<m; j++){
                sum = sum + a[i][j];
                if(sum <= k) cnt++;
            }
        }
        return cnt;
    }
};