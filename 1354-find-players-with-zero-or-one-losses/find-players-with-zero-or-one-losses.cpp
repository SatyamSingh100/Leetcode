class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        vector<vector<int>> v(2);
        int n=  a.size();
        map<int,int> win;
        map<int,int> lose;
        for(int i=0; i<n; i++){
            int num1 = a[i][0], num2 = a[i][1];
            win[num1]++;
            lose[num2]++;
        }

        for(auto it: win){
            int num = it.first;
            if(lose.find(num) == lose.end()){
                v[0].push_back(num);
        }
        }

        for(auto it: lose){
            int num = it.second, num1=it.first;
            if(num == 1) v[1].push_back(num1);
        }
        return v;
    }
};