class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size(),cnt=1,i=0,j=1,ans=1;
        unordered_map<int,int> m;
        if(n <= 2) return n;
        m[a[0]] =  0;
        while(j < n){
            if(m.find(a[j]) == m.end()){
                if(m.size() <= 1){
                    m[a[j]] = j; cnt++; j++;
                }
                else{
                    vector<pair<int,int>> v(2);
                    int k=0;
                    for(auto it: m){
                        v[k].first = it.first; 
                        v[k++].second = it.second;
                    }
                    if(v[0].second < v[1].second){
                        m.erase(v[0].first); i = v[0].second + 1;
                    }
                    else{
                        m.erase(v[1].first); i = v[1].second + 1;
                    }
                    m[a[j]] = j; ans = max(ans, cnt);
                    cnt = (j-i) + 1;  j++;
                }
            }
            else{
                m[a[j]] = j; cnt++; j++;
            }
        }
        ans = max(ans,cnt);
        return ans;

    }
};