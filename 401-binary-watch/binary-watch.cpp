class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int i=0;
        vector<int> a = {0,1,2,3,4,5,6,7,8,9,10,11};
        vector<int> b = {0};
        for(int i=1; i<=59; i++) b.push_back(i);
        int n1 = a.size(), n2 = b.size();
        vector<string> ans;

        while(i < n1){
            int j =0; 
            int num2 = num - __builtin_popcount(a[i]);
            while(j < n2){
                int val = __builtin_popcount(b[j]);
                if(val == num2){
                    string s ="";
                    s += to_string(a[i]) + ':';
                    if(b[j] <= 9) s += '0';
                    s += to_string(b[j]);
                    ans.push_back(s);
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};