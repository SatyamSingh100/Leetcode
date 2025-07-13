class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) {
        int n = a.size(),m=b.size(),cnt=0;
        sort(begin(a),end(a));
        sort(begin(b),end(b));
        int i=0,j=0;
        while(i < n && j<m){
            if(a[i] <= b[j]){
                cnt++; i++; j++;
            }
            else j++;
        }
        return cnt;
    }
};