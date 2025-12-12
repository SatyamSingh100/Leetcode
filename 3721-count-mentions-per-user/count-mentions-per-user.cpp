class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& a) {
        vector<int> ans(n,0),time(n,0);
        auto lambda = [&](vector<string>& v1,vector<string>& v2){
          int num1 = stoi(v1[1]), num2 = stoi(v2[1]);
            if(num1 == num2){
                return v1[0] > v2[0];
            }
            return num1 < num2;
        };
        sort(a.begin(),a.end(),lambda);
 
        for(int i=0; i<a.size(); i++){
            if(a[i][0] == "MESSAGE"){
                int t = stoi(a[i][1]);
                if(a[i][2] == "ALL"){
                    for(int j=0; j<n; j++) ans[j]++;
                }
                else if(a[i][2] =="HERE"){
                    for(int j=0; j<n; j++){
                        if(t >= time[j]) ans[j]++;
                    }
                }
                else{
                    string s = a[i][2]; int j = 0;
                    while(j < s.size()){
                        while(s[j] == 'i' || s[j] == 'd') j++;
                        string num = "";
                        while(s[j] != ' ' && j < s.size()){
                            num += s[j]; j++;
                        }
                        int val = stoi(num);
                        ans[val]++;
                        j++;
                    }
                }
            }
            else{
                int t_curr = stoi(a[i][1]);
                int t_next = t_curr + 60;
                int idx = stoi(a[i][2]);
                time[idx] = t_next;
            }
        }
        return ans;
    }
};