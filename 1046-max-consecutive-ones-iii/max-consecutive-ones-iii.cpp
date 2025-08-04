class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size(),i=0,j=0,cnt=0,ans=0;
        while(j < n){
            if(a[j] == 0){
                if(k > 0){
                    cnt++; j++; k--;
                }
                else{
                    ans = max(ans,cnt);
                    while(a[i] == 1){
                        i++; cnt--;
                    }
                    i++; j++;
                }
            } 
            else{
                cnt++; j++;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};