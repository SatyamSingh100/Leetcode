class Solution {
public:
    vector<int> twoSum(vector<int>& a, int tar) {
        int n= a.size(),i=0,j=n-1,ans1=-1,ans2=-1;
        while(i<j){
            int num1 = a[i], num2= a[j],sum = num1 + num2;
            if(sum == tar) {
                ans1 = i+1; ans2 = j+1;
                break;
            }
            else if(sum>tar) j--;
            else i++;
        }
        vector<int> v = {ans1, ans2};
        return v;
    }
};