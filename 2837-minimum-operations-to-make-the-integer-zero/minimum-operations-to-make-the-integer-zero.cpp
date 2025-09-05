class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2 > num1) return -1;
        int t = 1;
        while(true){
            long long val = (long long)num1 - (long long)t*num2;
            if(val < 0) return -1;
            int mini = __builtin_popcountll(val);
            if(t >= mini && t<= val) return t;
            t++;
        }
       return -1;
    }
};