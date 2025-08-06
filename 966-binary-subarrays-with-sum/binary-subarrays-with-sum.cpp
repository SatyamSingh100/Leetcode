class Solution {
public:
    int f(vector<int>& a, int tar){
        int n= a.size(),i=0,j=0,sum=0,cnt=0;
        if(tar < 0) return 0;
        while(j < n){
            sum += a[j];
            while(sum > tar) sum -= a[i++];
            if(sum <= tar) cnt += (j-i)+1;
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& a, int tar) {
       int ans = f(a,tar) - f(a,tar-1);
       return ans;
        
    }
};