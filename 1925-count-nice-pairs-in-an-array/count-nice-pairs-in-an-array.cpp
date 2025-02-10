class Solution {
public:
int rev(int num){
    int a=0;
    string s = to_string(num);
    int n= s.size();
    while(num>0){
        int b = num%10;
        a = a*10 + b;
        num = num/10;
    }
    return a;
}
    int countNicePairs(vector<int>& a) {
        int n= a.size();
        long long cnt=0;
        for(int i=0; i<n; i++){
            a[i] = a[i] - rev(a[i]);
        }
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            if(m.find(a[i]) == m.end()) m[a[i]] =1;
            else{
                cnt += m[a[i]];
                m[a[i]]++;}
        }
        long long d = 1e9 + 7;
        cnt = cnt %d ;
        return cnt;
    }
};