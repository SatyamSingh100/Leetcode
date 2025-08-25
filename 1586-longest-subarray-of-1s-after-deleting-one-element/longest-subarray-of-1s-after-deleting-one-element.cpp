class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size(),ans=0,cnt=0,i=0,j=0;
        while(j < n){
            if(a[j] == 0) cnt++;
            while(cnt > 1){
                if(a[i] == 0) cnt--;
                i++;
            }
            ans = max(ans, j - i);
            j++;
        }
        return ans;
    }
};