class Solution {
public:
    int findMinDifference(vector<string>& time) {
        int n= time.size();
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            int num1 = stoi(time[i].substr(0,2)), num2 = stoi(time[i].substr(3,2));
            a.push_back({num1,num2});
        }
        
        auto lambda =[&](pair<int,int>& p1, pair<int,int>& p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        };
        sort(begin(a),end(a),lambda);
        int ans = 60*(24 + a[0].first - a[n-1].first) + (a[0].second - a[n-1].second);
        for(int i=1; i<n; i++){
            int num = 60*(a[i].first - a[i-1].first) + (a[i].second - a[i-1].second);
            ans = min(ans,num);
        }
        return ans;

    }
};