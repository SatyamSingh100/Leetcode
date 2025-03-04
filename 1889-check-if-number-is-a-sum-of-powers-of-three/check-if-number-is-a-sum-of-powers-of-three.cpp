class Solution {
public:
    int f1(int n){
        int a =0;
        while(n >= pow(3,a)){
            a++;
        }
        return a-1;
    }
    bool f(int n){
        int num,a;
        vector<bool> v(17,false);
        while(n > 0){
        a = f1(n);
        if(v[a] == false){
        v[a] = true;
        num = pow(3,a);
        n = n - num;
        }
        else break;
        }
        if(n == 0) return true;
        return false;
    }
    bool checkPowersOfThree(int n) {
        if(n==1) return true;
        bool ans = f(n);
        return ans;
    }
};