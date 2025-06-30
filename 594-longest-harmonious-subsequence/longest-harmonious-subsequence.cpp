class Solution {
public:
    int findLHS(vector<int>& a) {
        int n= a.size(),ans=0;
        map<int,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        vector<pair<int,int>> v;
        for(auto it: m){
            v.push_back({it.first,it.second});
        }
        if(v.size() == 1) return 0;
        for(int i=0; i<v.size()-1; i++){
            if(v[i].first + 1 == v[i+1].first){
                ans = max(ans,v[i].second+ v[i+1].second);
            }
        }
        return ans;
    }
};