class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ans = countAndSay(n-1);

        string res = "";
        for(int i=0; i<ans.size(); i++){
            int cnt = 1;
            char c = ans[i];
            while(i< ans.size()-1 && ans[i] == ans[i+1]){
                cnt++; i++;
            }
            res += to_string(cnt) + string(1,c);
        }
        return res;
    }
};