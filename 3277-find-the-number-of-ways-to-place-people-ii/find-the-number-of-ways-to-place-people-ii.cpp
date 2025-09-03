class Solution {
public:
    int numberOfPairs(vector<vector<int>>& a) {
        int n =a.size(),ans=0;
        auto lambda = [&](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        };
        sort(a.begin(),a.end(),lambda);
        for(int i=0; i<n-1; i++){
            int y = 1e9;
            for(int j=i+1; j< n; j++){
                if(a[j][1] >= a[i][1] && y > a[j][1]){
                    ans++;
                    y = a[j][1];
                }
            }
        }
        return ans;
    }
};