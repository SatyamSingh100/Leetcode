class Solution {
public:
    int numberOfBeams(vector<string>& a) {
        int m = a.size(),n=a[0].size(),cnt=0,prev=0;
        for(int i=0; i<m; i++){
            int curr =0;
            for(int j=0; j<n; j++){
                if(a[i][j] == '1') curr++;
            }
            cnt += (curr*prev);
            if(curr != 0) prev = curr;
        }
        return cnt;
    }
};