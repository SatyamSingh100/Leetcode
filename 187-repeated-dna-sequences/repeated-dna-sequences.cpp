class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size(),i=0,j=9;
        unordered_map<string,int> m;
        unordered_set<string> ans;
        vector<string> v;
        if(n < 10) return v;
        while(j < n){
            string cur = s.substr(i,10);
            if(m.find(cur) == m.end()) m[cur]++;
            else{
                ans.insert(cur);
            }
            m[cur]++;
            i++; j++;
        }
        for(auto it: ans) v.push_back(it);
        return v;
    }
};