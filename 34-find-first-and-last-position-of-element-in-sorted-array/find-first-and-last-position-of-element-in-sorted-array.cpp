class Solution {
public:
    vector<int> searchRange(vector<int>& a, int k) {
        int n = a.size();
        int l=0,r=n-1;
        int st=-1,end=-1;
        vector<int> ans;
        while(l <= r){
            int mid = (l + r)/2;
            if(a[mid] == k){
                if(mid == 0) st = mid;
                else if(a[mid] > a[mid-1]) st = mid;
                else r = mid-1;
                if(st != -1) break;
            }
            else if(a[mid] > k) r = mid - 1;
            else l = mid + 1;
        }
        l = 0; r = n-1;
        while(l <= r){
            int mid = (l + r)/2;
            if(a[mid] == k){
                if(mid ==  n-1) end = mid;
                else if(a[mid] < a[mid+1]) end = mid;
                else l = mid + 1;
                if(end != -1) break;
            }
            else if(a[mid] > k) r = mid - 1;
            else l = mid + 1;
        }
        ans.push_back(st);
        ans.push_back(end);
        return ans;
    }
};