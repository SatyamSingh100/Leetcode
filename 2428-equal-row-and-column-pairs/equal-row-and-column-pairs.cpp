class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n= a.size(),cnt=0;
        map<vector<int>,int> m;
        for(int i=0; i<n; i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                v.push_back(a[i][j]);
            }
            if(m.find(v) == m.end()) m[v] =1;
            else m[v]++;
        }

        for(int j=0; j<n; j++){
            vector<int> v;
            for(int i=0; i<n; i++){
                v.push_back(a[i][j]);
            }
            if(m.find(v) != m.end()) cnt+= m[v];
        }
        return cnt;
    }
};