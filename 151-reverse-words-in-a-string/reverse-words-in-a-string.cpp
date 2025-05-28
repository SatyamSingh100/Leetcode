class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string token,ans;
        stringstream str(s);
        while(str >> token){
            v.push_back(token);
        }
        reverse(begin(v),end(v));
        for(int i=0; i<v.size(); i++){
            if(i!=0) ans += ' ';
            ans += v[i];
        }
        return ans;
    }
};