class Solution {
public:
    int f(int n){
        if(n == 1) return 0;
        int cnt =0;
        while(n > 1){
            n = n/2;
            cnt++;
        }
        return cnt;
    }
    vector<int> singleNumber(vector<int>& a) {
        int n = a.size();
        long num =0;
        vector<int> ans;
        if(n == 2) return a;
        for(int i=0; i<n; i++) num = num ^ a[i];
        long num1 = (num & (num-1)) ^ num;
        int idx = f(num1);
        int b1 =0,b2=0;
        for(int i=0; i<n; i++){
            if(a[i] & (1<<idx)) b1 = b1 ^ a[i];
            else b2 = b2 ^ a[i];
        }
        ans.push_back(b1);
        ans.push_back(b2);
        return ans;
    }
};