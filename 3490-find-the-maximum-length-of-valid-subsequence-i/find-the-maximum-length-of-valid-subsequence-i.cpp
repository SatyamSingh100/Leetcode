class Solution {
public:
    int maximumLength(vector<int>& a) {
        int n= a.size(),odd=0,even=0;
        for(int i=0; i<n; i++){
            if(a[i] & 1) odd++;
            else even++;
        }
        int cnt0 = max(odd,even);
        int c1=0,c2=0,val1=1,val2=0;
        for(int i=0; i<n; i++){
            if(a[i] % 2 == val1){
                c1++; val1 = !val1;
            }
            if(a[i] % 2 == val2){
                c2++;  val2 = !val2;
            }
        }
        int cnt1 = max(c1,c2);
        return max(cnt0,cnt1);
    }
};