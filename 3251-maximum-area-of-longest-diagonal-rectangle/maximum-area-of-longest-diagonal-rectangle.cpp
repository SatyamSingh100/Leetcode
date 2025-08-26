class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& a) {
        int n = a.size();
        vector<pair<int,int>> p(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                int l = a[i][0], b = a[i][1];
                int diag = (l*l) + (b*b);
                int area = l*b;
                p[i].first = diag; p[i].second = area;
            }
        }
        auto lambda  = [&](pair<int,int>& p1, pair<int,int>& p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first > p2.first;
        };
        sort(p.begin(),p.end(),lambda);
        return p[0].second;
    }
};