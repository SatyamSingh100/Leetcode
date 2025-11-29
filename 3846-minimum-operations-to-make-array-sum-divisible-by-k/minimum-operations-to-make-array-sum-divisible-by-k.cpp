class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int sum =0;
        for(int i=0; i<a.size(); i++) sum += a[i];
        int n = sum % k;
        return n;
    }
};