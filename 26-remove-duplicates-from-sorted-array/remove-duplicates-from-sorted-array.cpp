class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        int n = s.size(),i=0,j=1,cnt=1;
        while(j<n){
            if(s[i] == s[j]) j++;
            else if(s[i] != s[j]){
                s[++i] = s[j++];
                cnt++;
            }
        }
        return cnt;
    }
};