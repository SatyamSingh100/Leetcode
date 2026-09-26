class Solution {
public:
    string evaluate(string s, vector<vector<string>>& a) {
        unordered_map<string,string> m;
        for(int i=0; i<a.size(); i++){
            m.insert({a[i][0],a[i][1]});
        }
        int i=0; 
        string ans = "";
        while(i<s.size()){
            if(s[i] == '('){
                string cur = "";
                i++;
                while(s[i] != ')'){
                    cur += s[i]; i++;
                }
                if(cur != ""){
                    if(m.find(cur) == m.end()) ans += '?';
                    else ans += m[cur];
                }
                i++;
            }
            else{
                ans += s[i]; i++;
            }
        }
        return ans;
    }
};