class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n = a.size();
        vector<int> v(1e4 + 1,0);
        for(int i=0; i<a.size(); i++){
            v[a[i]]++;
        }
        for(int i=0; i<v.size(); i++){
            if(v[i] > 1) return i;
        }
        return -1;
    }
};