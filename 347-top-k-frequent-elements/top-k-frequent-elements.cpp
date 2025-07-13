class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        vector<pair<int,int>> v;
        for(auto it: m){
            v.push_back({it.second,it.first});
        }
        sort(begin(v),end(v));
        reverse(begin(v),end(v));
        vector<int> ans;
        for(int i=0; i<k; i++) ans.push_back(v[i].second);
        return ans;
    }
};