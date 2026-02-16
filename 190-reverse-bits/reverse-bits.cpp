class Solution {
public:
    int toDec(string s){
        int n = s.size(),c=0;
        long long sum =0;
        for(int i=n-1; i>=0; i--) sum += (s[i]-'0')*(pow(2,c++));
        return sum;
    }
    string toBin(int num){
        string ans ="";
        for(int i=0; i<32; i++) ans += '0';
        int z = 31;
        while(num > 0){
            if(num & 1) ans[z] = '1';
            z--;
            num = num/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int reverseBits(int n) {
        string ans = toBin(n);
        int val = toDec(ans);
        return val;
    }
};