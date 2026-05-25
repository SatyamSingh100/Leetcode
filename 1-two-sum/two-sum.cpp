class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        int n = a.size();
        vector<int> ans(2,-1);
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            int num1 = a[i];
            int num2 = k - a[i];
            if(m.find(num2) != m.end()){
                ans[0] = i;
                ans[1] = m[num2];
                return ans;
            }
            m[num1] = i;
        }
        return ans;
    }
};