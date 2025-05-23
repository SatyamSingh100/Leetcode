class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        int currSum =0,maxSum = -1e9;
        for(int i=0; i<n; i++){
            currSum += a[i];
            maxSum =  max(maxSum,currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};