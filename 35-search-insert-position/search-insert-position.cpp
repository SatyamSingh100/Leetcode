class Solution {
public:
    int searchInsert(vector<int>& a, int tar) {
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i] == tar) return i;
            else if(a[i] > tar) return i;
        }
        return n;
    }
};