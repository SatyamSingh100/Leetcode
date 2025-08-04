class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size(),cnt=0,ans=0;
        int i=0,j=0;
        unordered_map<int,int> m;
        while(j < n){
            m[a[j]]++; cnt++;
            if(m.size() > 2){
                ans = max(ans,cnt-1);
                while(m.size() > 2){
                    m[a[i]]--;
                    if(m[a[i]] == 0) m.erase(a[i]);
                    i++;
                }
                cnt = j - i + 1;
            }
            j++;
        }
        ans = max(ans,cnt);
        return ans;
    }
};