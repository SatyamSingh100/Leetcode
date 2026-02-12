class Solution {
public:
    int longestBalanced(string a) {
        int n = a.size(),i=0,ans=0;
        if(n == 1) return 1;
        while(i < n-1){
            int j = i+1;
            unordered_map<char,int> m;
            m[a[i]]++;
            while(j < n){
                m[a[j]]++;
                int prev = -1;
                for(auto it: m){
                    if(prev == -1) prev = it.second;
                    else if(it.second != prev){
                        prev = -2;
                        break;
                    }
                }
                if(prev != -2) ans = max(ans,j-i+1);
                j++;
            }
            i++;
        }
        return ans;
    }
};