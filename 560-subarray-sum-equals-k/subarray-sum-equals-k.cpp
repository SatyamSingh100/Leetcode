class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size(),preSum= 0,cnt=0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(int i=0; i<n; i++){
            preSum += a[i];
            int req = preSum - k;
            if(mpp.find(req) != mpp.end()) cnt += mpp[req];
            
            if(mpp.find(preSum) == mpp.end()) mpp[preSum] = 1;
            else mpp[preSum] += 1;
        }
        return cnt;
    }
};