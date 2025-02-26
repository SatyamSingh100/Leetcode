class Solution {
public:
    bool wordPattern(string se, string s) {
        int n = se.size();
        stringstream ss(s);
        string word;
        vector<string> v;
        while(ss >> word){
            v.push_back(word);
        }
        int numi = v.size();
        if(numi != n) return false;
        unordered_map<char,string> m;
        unordered_map<string,int> m2;
        for(int i=0; i<n; i++){
            char c = se[i];
            if(m.find(c) == m.end()){
                if(m2.find(v[i]) == m2.end()){
                m[c] = v[i];
                m2[v[i]] = 1;
                }
                else return false;
            }
            else {
                m2[v[i]]++;
                if(m[c] != v[i]) return false;
            }
        }
        return true;
    }
};