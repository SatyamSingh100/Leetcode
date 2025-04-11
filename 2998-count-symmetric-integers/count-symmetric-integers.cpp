class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        vector<string> v;
        for(int i=low; i<= high; i++){
            string s = to_string(i);
            v.push_back(s);
        }
        int cnt=0;
        for(int i=0; i<v.size(); i++){
            if(v[i].size() % 2 == 0){
                string se = v[i];
                int ans1=0,ans2=0;
                for(int j= 0; j<se.size()/2; j++){
                    int num = se[j] - '0';
                    ans1 += num;
                }
                for(int j=se.size()/2; j<se.size(); j++){
                    int num = se[j] - '0';
                    ans2 += num;
                }
                if(ans1 == ans2) cnt++;
            }
        }
        return cnt;
    }
};