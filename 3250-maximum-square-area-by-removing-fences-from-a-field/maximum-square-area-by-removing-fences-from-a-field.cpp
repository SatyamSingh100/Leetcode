class Solution {
public:
    int maximizeSquareArea(int r, int c, vector<int>& h, vector<int>& v) {
        h.push_back(1);    h.push_back(r);
        v.push_back(1);    v.push_back(c);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long long c2 = 1e9 + 7;
        unordered_set<int> v1,v2;
        for(int i=0; i<h.size()-1; i++){
            for(int j=i+1; j<h.size(); j++){
                int num = abs(h[i] - h[j]);
                v1.insert(num);
            }
        }
        for(int i=0; i<v.size()-1; i++){
            for(int j=i+1; j<v.size(); j++){
                int num = abs(v[i] - v[j]);
                v2.insert(num);
            }
        }
        int ans = -1;
        for( auto it: v1){
           if(v2.contains(it)){
            ans = max(ans,it);
           }
        }
        if(ans <= 0) return ans;
        ans = 1ll * ans * ans % 1000000007;
        return ans;
    }
};