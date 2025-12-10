class Solution {
public:
    int countPermutations(vector<int>& a) {
        int n = a.size();
        bool check = true;
        long long cnt = (1e9+7);
        if(n == 1) return 1;
        for(int i=1; i<n; i++){
            if(a[i] <= a[0]) check = false;
        }
        if(check == false) return 0;
        long long ans = 1,val=1;
        for(int i=1; i<n; i++){
            long long pro = ((ans * (val)) % cnt);
            val++;
            ans = pro;
        }
        ans = ans % cnt;
        return ans;
    }
};