class Solution {
public:
    bool f(vector<int>& a){
        int n = a.size();
        if(n == 1) return true;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            int num = a[i];
            if(m.find(num) == m.end()) m[num] =1;
            else m[num]++;
        }
        if(m.size() < n) return false;
        return true;
    }

    int minimumOperations(vector<int>& a) {
        int n = a.size(),cnt=0,ans=-1;
        unordered_map<int,int> m;
        for(int i=n-1; i>=0; i--){
            int num = a[i];
            if(m.find(num) == m.end()) m[num] =1;
            else{
            ans =i+1; break;}
        }
        if(ans == -1) return 0;
        if(ans % 3 == 0) cnt += (ans)/3;
        else cnt += ((ans)/3) + 1;
        return cnt;
    }
};