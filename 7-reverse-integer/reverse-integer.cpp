class Solution {
public:
    int reverse(int n) {
        if(n >= pow(2,31) || n <= -pow(2,31)) return 0;
        bool sign = true;
        if(n < 0) sign = false;
        long long num =0;
        n = abs(n);
        while(n > 0){
            int rem = n % 10;
            n = n /10;
            num = (num * 10) + rem;
            if(num >= pow(2,31)) return 0;
        }
        int val = num;
        if(sign == false) val = -val;
        return val;
    }
};