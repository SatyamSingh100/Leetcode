class Solution {
public:
    int majorityElement(vector<int>& a) {
        //Moore's Voting Algorithn..
        int n = a.size();

        //Assume the first element as Majority Element and make its cnt as 1
        int me = a[0],cnt=1;

        //Run a loop till n-1
        for(int i=1; i<n; i++){

            //If the current element is the same as Maj. Elem, then simply inc its cnt by 1
            if(a[i] == me) cnt++;
            //Else dec by 1;
            else{
                cnt--;
            }
            //And if the cnt becomes 0,then change ur majority elem to a[i] and make its cnt as 1
            if(cnt == 0){
                me = a[i]; cnt = 1;
            }
        }
        return me;

    }
};