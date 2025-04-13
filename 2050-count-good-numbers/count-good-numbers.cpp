class Solution {
public:
    long long power(long long a, long long b){
        if(b == 0) return 1;
        int d = 1000000007;
        long long num = power(a,b/2);
        long long ans = ((num%d)*(num%d))%d;
        if(b%2 != 0) ans *= a;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long ans1=-1,ans2=-1,result= -1;
        long long d = 1000000007;
        if(n % 2 == 0){
            long long num1 = n/2, num2 = n/2;
            ans1 = power(5,num1);
            ans2 = power(4,num2);
             result = (((ans1 %d)%d) *((ans2 % d)%d)) % d;
        }
        else{
            long long num1 = (n/2) + 1, num2 = (n/2);
            ans1 = power(5,num1);
            ans2 = power(4,num2);
             result = (((ans1 %d)%d) *((ans2 % d)%d)) % d;
        }
        // result = result%(1000000007);
        return result;
    }
};