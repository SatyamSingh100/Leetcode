class Solution {
public:
    int numWaterBottles(int num1, int num2) {
        int cnt2 =0,n = num1;
        while(n >= num2){
            cnt2 += n/num2;
            int n1 = n/num2;
            int n2 = n % num2;
            n = n1 + n2;
        }
        return (num1 + cnt2);
        
    }
};