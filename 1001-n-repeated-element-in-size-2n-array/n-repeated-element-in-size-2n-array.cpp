class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n = a.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        for(auto it: m){
            if(it.second > 1) return it.first;
        }
        return -1;
    }
};