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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* t1 = head1; ListNode* t2 = head2;
        int car =0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(t1 != NULL || t2 != NULL){
            int sum =car;
            if(t1 != NULL) sum += t1->val;
            if(t2 != NULL) sum += t2->val;
            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr -> next;
            car = sum/10;
            if(t1 != NULL) t1 = t1->next;
            if(t2 != NULL) t2 = t2->next;
        }
        if(car != 0){
            ListNode* nod = new ListNode(car);
            curr-> next = nod;
        }
        return dummy->next;
    }
};