class Solution {
public:
    int alternatingSum(vector<int>& a) {
        int s1=0,s2=0,n=a.size();
        for(int i=0; i<n; i++){
            if(i & 1) s1 += a[i];
            else s2 += a[i];
        }
        return (s2-s1);
    }
};