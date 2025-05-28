class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i=0; i<n; i++) m[s[i]]++;

        vector<pair<char,int>> v;
        for(auto it: m){
            char c = it.first; int num = it.second;
            v.push_back({c,num});
        } 

        auto lambda = [&](pair<char,int> &p1, pair<char,int> &p2){
            return p1.second > p2.second;
        };

        sort(begin(v),end(v),lambda);
        string ans = "";
        for(int i=0; i<v.size(); i++){
            char c = v[i].first; int num = v[i].second;
            for(int j=0; j<num; j++) ans += v[i].first;
        }
        return ans;
    }
};