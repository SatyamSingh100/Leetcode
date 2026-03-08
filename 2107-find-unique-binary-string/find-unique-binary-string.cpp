class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        int n = a.size();

        string s = "";
        for(int i=0; i<n; i++) s += '0';
        vector<string> b(n+1,s);
        for(int i=1; i<=n; i++){
            b[i][i-1] = '1';
        }
        unordered_map<string,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        for(int i=0; i<=n; i++){
            if(m.find(b[i]) == m.end()) return b[i];
        }
        return s;
    }
};