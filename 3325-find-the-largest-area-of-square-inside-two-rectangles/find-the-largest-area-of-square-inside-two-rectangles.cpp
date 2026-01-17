class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        long long ans = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int l1 = min(b[i][0],b[j][0]) - max(a[i][0],a[j][0]);
                int r1 = min(b[i][1],b[j][1]) - max(a[i][1],a[j][1]);
                long long len = min(l1,r1);
                if(len < 0) continue;
                len = len * len;
                ans = max(ans,len);
            }
        }
        return ans;
    }
};