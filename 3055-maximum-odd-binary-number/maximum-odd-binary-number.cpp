class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), cnt=0,idx=0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt+=1;
        }
        string ans(n,'0');
        ans[n-1] = '1';
        cnt--;
        while(cnt > 0){
            ans[idx] = '1';
            idx++;
            cnt--;
        }
        return ans;
    }
};