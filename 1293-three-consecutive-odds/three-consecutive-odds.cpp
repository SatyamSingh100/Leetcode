class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        for(int i=2; i<a.size(); i++){
            int num1 = a[i-2],num2 =a[i-1], num3 = a[i];
            if( (num1&1) && (num2&1) && (num3&1)) return true;
        }
        return false;
    }
};