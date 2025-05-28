class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        for(int i=0; i<7; i++){
            m['I'] = 1; m['V'] = 5; m['X'] = 10; m['L'] = 50; m['C'] = 100; m['D'] = 500; 
            m['M'] = 1000; 
        }
        int mini = 1e9,sum=0;
        for(int i=0; i<s.size(); i++){
            char c = s[i]; int num = m[c];
            if(num > mini){
                sum = sum - mini;
                sum += num- mini;
            }
            else{
                sum += num;
            }
            mini = min(mini,num);
        }
        return sum;
    }
};