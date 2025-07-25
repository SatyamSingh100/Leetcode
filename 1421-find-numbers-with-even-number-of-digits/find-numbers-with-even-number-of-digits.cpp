class Solution {
public:
    int findNumbers(vector<int>& a) {
        int cnt=0,n=a.size();
        for(int i=0; i<n; i++){
            string cur = to_string(a[i]);
            if(cur.size() % 2 == 0) cnt++;
        }
        return cnt;
    }
};