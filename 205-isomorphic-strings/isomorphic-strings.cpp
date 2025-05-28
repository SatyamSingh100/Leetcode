class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> m,mp;
        for(int i=0; i<n; i++){
            char c1 = s[i], c2 = t[i];
            if(m.find(c1) == m.end()) m[c1] = c2;
            else{
                if(m[c1] != c2) return false; 
            }

            if(mp.find(c2) == mp.end()) mp[c2] = c1;
            else{
                if(mp[c2] != c1) return false; 
            }
        }
        return true;
    }
};