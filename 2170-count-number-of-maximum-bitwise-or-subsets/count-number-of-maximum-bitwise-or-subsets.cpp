class Solution {
public:
    int countSubsets(int idx, int maxi, int curr, vector<int>& a){
        if(idx == a.size()){
            if(curr == maxi) return 1;
            return 0;
        }

        int take = countSubsets(idx+1, maxi, curr | a[idx], a);
        int ntake = countSubsets(idx+1, maxi, curr, a);
        return take + ntake;
    }
    int countMaxOrSubsets(vector<int>& a) {
        int n = a.size(),maxi=0;
        for(int i=0; i<n; i++) maxi = maxi | a[i];
        int ans = countSubsets(0,maxi,0,a);
        return ans;
    }
};