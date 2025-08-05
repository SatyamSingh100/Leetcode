class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0,j=0,ans=0,len=0,maxf=0;
        unordered_map<int,int> m;
        while(j < n){
            m[s[j]]++;
            maxf = max(maxf,m[s[j]]);
            len = (j-i+1);
            if(len - maxf <= k) ans = max(ans,len);
            else{
                while((j-i+1) - maxf > k){
                maxf = 0; m[s[i]]--;
                for(auto it: m) maxf = max(maxf,it.second);
                i++;
                }
            }
            j++;
        }
        // ans = max(ans,j-i+1);
        return ans;
    }
};