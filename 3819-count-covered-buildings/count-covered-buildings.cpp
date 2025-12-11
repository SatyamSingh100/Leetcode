class Solution {
public:
    int countCoveredBuildings(int n000, vector<vector<int>>& a) {
        int n = a.size();
        unordered_map<int,int> x,y;
        sort(a.begin(),a.end());
        int cnt=0;
        vector<bool> forw(n),back(n);
        for(int i=0; i<n; i++){
            int x1 = a[i][0], y1 = a[i][1];
            bool c1 = false,c2=false;
            if(x.find(x1) != x.end()) c1 = true;
            if(y.find(y1) != y.end()) c2 = true;
            forw[i] = c1 & c2;
            x[x1]++; y[y1]++;
        }
        unordered_map<int,int> w,z;
        for(int i=n-1; i>=0; i--){
            int x1 = a[i][0], y1 = a[i][1];
            bool c1 = false,c2=false;
            if(w.find(x1) != w.end()) c1 = true;
            if(z.find(y1) != z.end()) c2 = true;
            back[i] = c1 & c2;
            w[x1]++; z[y1]++;
        }
        for(int i=0; i<n; i++){
            bool ans = forw[i] & back[i];
            if(ans) cnt++;
        }
        return cnt;
    }
};