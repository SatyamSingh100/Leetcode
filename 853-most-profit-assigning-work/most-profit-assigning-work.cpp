class Solution {
public:
    int maxProfitAssignment(vector<int>& dif, vector<int>& prof, vector<int>& a) {
        int n = dif.size(),m= a.size();
        sort(begin(a),end(a));  reverse(begin(a),end(a));
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({prof[i],dif[i]});
        }
        sort(begin(v),end(v));
        reverse(begin(v),end(v));
        int i=0,j=0,cnt=0;
        while(i < m && j< n){
            if(a[i] < v[j].second) j++;
            else {
                cnt += v[j].first;
                i++;
            }
        }
        return cnt;
    }
};