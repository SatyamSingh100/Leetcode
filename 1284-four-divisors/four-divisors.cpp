class Solution {
public:
    vector<int> div(int& num){
        vector<int> ans = {1};
        if(num == 1) return ans;
        ans.push_back(num);
        int k = sqrt(num);
        if(k * k == num) ans.push_back(k);
        for(int i=2; i<=k; i++){
            if(num % i == 0){
                ans.push_back(num/i);
                ans.push_back(i);
            }
        }
        return ans;
    }
    int sumFourDivisors(vector<int>& a) {
        int n = a.size(),sum=0;
        for(int i=0; i<n; i++){
            vector<int> ans = div(a[i]);
            if(ans.size() == 4){
                for(int j=0; j<ans.size(); j++) sum += ans[j];
            }
        }
        return sum;
    }
};