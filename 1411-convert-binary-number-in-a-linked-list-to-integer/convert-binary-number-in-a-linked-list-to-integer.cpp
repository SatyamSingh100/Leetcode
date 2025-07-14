/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr = head;
        stack<int> st;
        while(curr != nullptr){
            st.push(curr->val);
            curr = curr -> next;
        }
        int ans=0,idx=0;
        while(!st.empty()){
            ans += pow(2,idx++) * st.top();
            st.pop();
        }
        return ans;
    }
};