class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i=0; i<30; i++){
            int num1 = start & (1<<i);
            int num2 = goal & (1<<i);
            if(num1 ^ num2) cnt++;
        }
        return cnt;
    }
};