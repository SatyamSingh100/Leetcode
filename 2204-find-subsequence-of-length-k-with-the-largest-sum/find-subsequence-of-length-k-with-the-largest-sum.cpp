class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        // sort(a.begin(),a.end());
        int idx =k,n=a.size();
        vector<int> ans;
        vector<pair<int,int>> v;
		for(int i=0; i<n; i++){
			v.push_back({a[i],i});
		}
        auto lambda = [&](pair<int,int>& p1, pair<int,int>& p2){
			return p1.first > p2.first;
		};
		sort(v.begin(),end(v),lambda);
		auto lambda2 = [&](pair<int,int>& p1, pair<int,int>& p2){
			return p1.second < p2.second;
		};
		sort(begin(v),begin(v)+k, lambda2);
        for(int i=0; i<k; i++) ans.push_back(v[i].first);
        return ans;
    }
};