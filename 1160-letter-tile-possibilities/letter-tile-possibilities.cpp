class Solution {
public:
    int f(string a,string result,unordered_set<string>& s,vector<bool>& v){
        int n = a.size();
        s.insert(result);
        for(int i=0; i<n; i++){
            if(v[i] == true) continue;
            else{
                v[i] = true;
                result.push_back(a[i]);

                f(a,result,s,v);

                v[i] = false;
                result.pop_back();
            }
        }
        return s.size() - 1;

    }
    int numTilePossibilities(string a) {
        int n = a.size();
        vector<bool> v(n,0);
        unordered_set<string> s;
        string result ="";
        int ans = f(a,result,s,v);
        return ans;

    }
};