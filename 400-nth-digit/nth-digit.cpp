class Solution {
public:
    int findNthDigit(long long n) {
        long long a=1,b=9,t=1;
        while(n - ((b-a+1)*t) > 0){
            n -=  (b-a+1) * t;
            a = a*10;
            b = b*10 + 9; t++;
        }

        long long num,idx;
        if(n % t == 0){
            num = a + (n/t) -1;  idx = t-1;
        }
        else{
            num = a + (n/t); idx = (n%t) - 1;
        }
        string s = to_string(num);
        long long val = s[idx] - '0';
        return val;
    }
};