class Solution {
public:
    int minimumPushes(string a) {
        int n = a.size(),ans=0;
        for(int i=0; i<n; i++){
            ans += (i/8) +1;
        }
        return ans;
    }
};