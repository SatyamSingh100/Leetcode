class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        sort(begin(a),end(a));
        if(n == 0) return 0;
        int cnt =1,ans=1;
        for(int i=1; i<n; i++){
            if(a[i] == a[i-1]) continue;
            if(a[i] == a[i-1] + 1) cnt++;
            else{
                ans= max(ans,cnt); cnt=1;
            }
        }
        ans = max(ans,cnt);
        return ans;        
    }
};