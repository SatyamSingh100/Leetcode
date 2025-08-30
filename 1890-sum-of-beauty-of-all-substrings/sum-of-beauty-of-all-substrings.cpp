class Solution {
public:
    int f(string& a){
        int n = a.size(),mini = 1e9,maxi =-1;
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            v[a[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(v[i] != 0){
                maxi = max(maxi,v[i]);
                mini = min(mini, v[i]);
            }
        }
        return maxi - mini;
    }
    int beautySum(string s) {
        int n = s.size(),sum=0;
        for(int i=0; i<n-1; i++){
            string ans = "";
            for(int j=i; j<n; j++){
                ans += s[j];
                int num = f(ans);
                sum += num;
            }
        }
        return sum;
    }
};