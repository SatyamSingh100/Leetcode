class Solution {
public:
    int findLucky(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        int ans =-1;
        for(auto it: m){
            if(it.first == it.second) ans = max(ans,it.first);
        }
        return ans;
    }
};