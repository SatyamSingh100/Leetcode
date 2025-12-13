class Solution {
public:  
    bool f1(string& s){
        int n = s.size();
        if(s == "") return false;
        for(int i=0; i<n; i++){
            if((s[i] >= 65 && s[i] <= 90) || (s[i] == 95) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& a, vector<string>& b, vector<bool>& c) {
        int n = a.size();
        vector<bool> ans(n,true);
        vector<string> val;
        for(int i=0; i<n; i++){
            string s = a[i];
            bool seek = f1(s);
            if(seek == false) ans[i] = ans[i] & false; 
        }
        for(int i=0; i<n; i++){
            if((b[i] != "pharmacy") && (b[i] != "grocery") && (b[i] != "restaurant") && (b[i] != "electronics")) ans[i] = ans[i] & false;
        }
        for(int i=0; i<n; i++){
            if(c[i] != true) ans[i] = ans[i] & false;
        }
        vector<pair<string,string>> v;
        for(int i=0; i<n; i++){
            if(ans[i] == true) v.push_back({a[i],b[i]});
        }
        auto lambda = [&](pair<string,string>& p1,pair<string,string>& p2){
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        };
        sort(v.begin(),v.end(),lambda);  
        for(int i=0; i<v.size(); i++) val.push_back(v[i].first);
        return val;
    }
};