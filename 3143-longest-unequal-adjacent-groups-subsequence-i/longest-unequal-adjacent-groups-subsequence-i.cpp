class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(),prev = groups[0];
        vector<int> idx;
        vector<string> ans;
        idx.push_back(0);
        for(int i=1; i<n; i++){
            if(groups[i] != prev) idx.push_back(i), prev = groups[i];
        }
        for(int i=0; i<idx.size(); i++) ans.push_back(words[idx[i]]);
        return ans;
    }
};