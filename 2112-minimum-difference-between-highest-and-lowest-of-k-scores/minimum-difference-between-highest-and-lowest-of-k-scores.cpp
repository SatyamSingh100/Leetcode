class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size(),ans=1e9;
        sort(a.begin(),a.end());
        for(int i=0; i<=n-k; i++){
            int num1 = a[i], num2 = a[i+k-1];
            int diff = abs(num1 - num2);
            ans = min(ans,diff);
        }
        if(ans == 1e9) ans = 0;
        return ans;
    }
};