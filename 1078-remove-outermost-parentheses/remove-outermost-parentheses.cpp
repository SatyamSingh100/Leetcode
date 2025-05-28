class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size(),cnt=0;
        vector<int> v;
        for(int i=0; i<n; i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0) v.push_back(i);
        }
        reverse(begin(v),end(v));
        for(int i=0; i<v.size(); i++){
            if(i != 0) s.erase(s.begin() + v[i] + 1);
            s.erase(s.begin() + v[i]);
        }
        s.erase(s.begin());
        return s;
    }
};