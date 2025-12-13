class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long num =0,val=x;
        while(x){
            long long rem = x % 10;
            num = num*10 + rem;
            x = x/10;
        }
        return num == val;
    }
};