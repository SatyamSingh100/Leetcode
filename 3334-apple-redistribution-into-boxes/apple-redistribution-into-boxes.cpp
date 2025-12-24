class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int sum =0;
        for(int i=0; i<n; i++) sum += a[i];
        sort(b.begin(),b.end(),greater<int>());
        int i = 0,cnt=0;
        while(i < m && sum > 0){
            if(sum <= 0) break;
            sum -=  b[i];
            i++; cnt++;
        }
        return cnt;
    }
};