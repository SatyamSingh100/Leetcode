class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> isPrime(1e6+1,true);
        isPrime[0] = false; isPrime[1] = false;

        for(int i=2; i*i<=1e6; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=1e6; j+=i) isPrime[j] = false;
            }
        }
        int cnt =0;
        for(int i=left; i<=right; i++){
            int ans = __builtin_popcount(i);
            if(isPrime[ans]) cnt ++;
        }
        return cnt;
    }
};