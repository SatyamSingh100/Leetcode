class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size(),idx =-1;
        int i= 0, j= n-1;
        while(i <= j){
            int mid = (i + j)/2;
            if(a[mid] == target) return mid;
            else if(a[i] <= a[mid]){                      // Left Half sorted
                if(target >= a[i] && target < a[mid]) j = mid - 1;
                else i = mid + 1;
            }
            else{
                if(target > a[mid] && target <= a[j]) i = mid + 1;
                else j = mid - 1;
            }
        }
        return idx;
    }
};