class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> a;
        
        while(n >= 1){
            string s = to_string(n);
            if(s.size() == 1){
                a.push_back(n); break;
            }
            int num2 = pow(10,s.size()-1);
            int val = n % num2;
            a.push_back(n - val);
            n = val;
        }
        return a;
    }
};