class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> ans(2,-1);
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++){
            v[i].first = a[i];
            v[i].second = i;
        }
        int i = 0, j=n-1;
        sort(v.begin(),v.end());
        while(i < j){
            int num1 = v[i].first, num2 = v[j].first;
            int sum =  num1 + num2;
            if(sum == k){
                ans[0] = v[i].second; ans[1] = v[j].second;
                return ans;
            }
            else if(sum > k) j--;
            else i++;
        }
        return ans;
    }
};