class Solution {
public:
    int countDays(int n, vector<vector<int>>& v) {
        int cnt=0,lday = -1e9;

        // vector<bool> ans(n+1,false);
        sort(v.begin(),v.end());

        for(int i=0; i<v.size(); i++){
            int num1 = v[i][0], num2 = v[i][1];
            
            if(i == 0) cnt += (num1 - 1);
            else {
                if(v[i][0] > lday) cnt += (v[i][0] - lday -1);
            }
            lday = max(num2,lday);
            if(i == (v.size()-1) && lday < n) cnt += (n-lday);
        } 

        // for(int i=1; i<=n; i++){
        //     if(ans[i] == false) cnt++;
        // }
        return cnt;
    }
};