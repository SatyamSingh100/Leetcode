class Solution {
public:
    int countHillValley(vector<int>& a) {
        auto n2 = unique(a.begin(),a.end());
        a.erase(n2,a.end());

        int n = a.size(),ans=0;
        if(n <= 2) return 0;
        for(int i=1; i<n-1; i++){
            if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) ans += 1;
        }
        return ans;
    }
};