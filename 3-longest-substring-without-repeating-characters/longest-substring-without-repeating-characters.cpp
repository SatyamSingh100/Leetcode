class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),cnt=0,ans=0;
        unordered_map<char,int> m;
        int i=0,j=0;
        while(j < n){
            if(m.find(s[j]) == m.end()){
                m[s[j]] = 1; cnt++;
            }
            else{
                ans = max(ans,cnt);
                while(m.find(s[j]) != m.end()){
                    m[s[i]]--; cnt--;
                    if(m[s[i]] == 0) m.erase(s[i]);
                    i++;
                }
                m[s[j]] = 1; cnt++;
            }
            j++;
        }
        ans = max(ans,cnt);
        return ans;
    }
};