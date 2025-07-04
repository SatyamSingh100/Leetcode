class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        unordered_map<int,int> m1;
        unordered_map<char,int> m; 
        // m = m1;
        int cnt=0,ans=0,n= a.size();
        for(int i=0; i<a.size(); i++){
            if(m.find(a[i]) == m.end()){
                m[a[i]] = i; cnt++;
            }
            else{
                ans = max(ans,cnt);
                cnt = min(++cnt, i - m[a[i]]);
                // unordered_map<char,int> m1;
                m[a[i]] =i;
            }
        }
        ans = max(ans,cnt);
        return ans;
    }
};