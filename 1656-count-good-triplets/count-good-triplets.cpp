class Solution {
public:
    int countGoodTriplets(vector<int>& v, int a, int b, int c) {
        int n = v.size(),cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int num1 = abs(v[i] - v[j]), num2 = abs(v[j] - v[k]), num3 = abs(v[i] - v[k]);
                    if(num1 <= a && num2 <= b && num3 <= c) cnt++;
                }
            }
        }
        return cnt;
    }
};