class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.size() != t.size()) return false;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            char c=  t[i];
            if(m.find(c) != m.end()){
                 m[c]--;
                 if(m[c] == 0) m.erase(c);
            }
            else if(m.find(c) == m.end()) return false;
        }
        return true;
    }
};