class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size(),cnt=0;
        long long mini=1e5;
        long long sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] < 0) cnt++;
                long long val = abs(a[i][j]);
                sum += val;
                mini = min(mini,val);
            }
        }
        if(cnt & 1) sum -= 2*mini;
        return sum;
    }
};