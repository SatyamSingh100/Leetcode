class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {

        // Via merged Array Approach.... O(n+m)
    //     int n1 = a.size(),n2 = b.size();
    //     int i=0,j=0,cnt=0;
    //     int idx1 = ((n1+n2)/2) - 1, idx2 = (n1+n2)/2;
    //     double el1 = 0, el2 = 0;
    //     while(i < n1 && j < n2){
    //         if(a[i] > b[j]){
    //             if(cnt == idx1) el1 = b[j];
    //             if(cnt == idx2) el2 = b[j];
    //             j++; cnt++;
    //         }
    //         else{
    //             if(cnt == idx1) el1 = a[i];
    //             if(cnt == idx2) el2 = a[i];
    //             i++; cnt++;
    //         }
    //     }
    //     while(i < n1){
    //         if(cnt == idx1) el1 = a[i];
    //         if(cnt == idx2) el2 = a[i];
    //         i++; cnt++;
    //     }
    //     while(j < n2){
    //         if(cnt == idx1) el1 = b[j];
    //         if(cnt == idx2) el2 = b[j];
    //         j++; cnt++;
    //     }
    //     if((n1+n2) & 1) return el2;
    //     return (el1+el2)/2;


    // Via Binary Search... O(log(m+n))
    vector<int> a,b;
    if(num1.size() > num2.size()){
        a = num2; b = num1;
    }
    else{
        a = num1; b = num2;
    }
    int n = a.size(), m = b.size();
    int l = 0, r = min(n,m);
    int num = (n + m)/2;
    double ans = 0;

    while(l <= r){
        int mid = (l+r)/2;
        double l1 =-1e9,l2=l1,r1=1e9,r2=r1;
        int idx1 = mid, idx2 = num - idx1;
        if(idx1 >= 0 && idx1 < n) r1 = a[idx1];
        if(idx2 >= 0 && idx2 < m) r2 = b[idx2];
        if(idx1 > 0) l1 = a[idx1 - 1];
        if(idx2 > 0) l2 = b[idx2 - 1];
       
        if(l1 <= r2 && l2 <= r1){
            if((m+n) & 1){
                return min(r1,r2);
            }
            else {
                ans = (max(l1,l2) + min(r1,r2))/2;
            }
            break;
        }
        else if(l1 > r2) r = mid - 1;
        else l = mid + 1;
    }
    return ans;
    }
};