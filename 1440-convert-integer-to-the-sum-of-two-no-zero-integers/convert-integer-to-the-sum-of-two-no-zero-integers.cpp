class Solution {
public:
    bool f(int a, int b){
        string s1 = to_string(a), s2 = to_string(b);
        for(int i=0; i<s1.size(); i++){
            if(s1[i] == '0') return false;
        }
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == '0') return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> v;
        int a=1,b=n-1;
        for(int i=1; i<=n/2; i++){
            a = i;
            b = n - a;
            if(f(a,b)){
                v.push_back(a);
                v.push_back(b);
                break;
            }
        }
        return v;
    }
};