class Solution {
public:
    int minimumPushes(string a) {
        int n=a.size(),ans=0;
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            int num = a[i] - 97;
            v[num]++;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            if(v[i] != 0){
                ans += v[i] *((i/8) + 1);
            }
        }
        return ans;
    }
};