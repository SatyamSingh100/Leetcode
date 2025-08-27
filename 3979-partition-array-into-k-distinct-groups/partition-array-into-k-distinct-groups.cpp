class Solution {
public:
    bool partitionArray(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        if(n % k != 0) return false;
        int p = n/k;
        for(auto it : m){
            if(it.second > p) return false;
        }
        return true;
    }
};