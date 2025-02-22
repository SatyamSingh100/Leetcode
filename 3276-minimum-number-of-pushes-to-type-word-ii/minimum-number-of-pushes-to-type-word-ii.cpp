class Solution {
public:
    int minimumPushes(string a) {
        int n= a.size();
        vector<int> v(26);
        for(int i=0; i<n; i++){
            int num = a[i] - 97;
            v[num]++;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(),v.end());
        int cnt=1, idx =2,sum=0;
        for(int i=0; i<v.size(); i++){
            if(idx >9){
                idx =2;
                cnt++;
                sum += (v[i])*cnt;
            }
            else{
                sum += (v[i])*cnt;
            }
            idx++;
        }
        return sum;
    }
};