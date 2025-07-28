class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        int n = a.size();
        unordered_map<string, vector<string>> m;
        for(int i=0; i<n; i++){
            string curr = a[i];
            sort(curr.begin(),curr.end());
            m[curr].push_back(a[i]);
        }
        vector<vector<string>> ans;
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};