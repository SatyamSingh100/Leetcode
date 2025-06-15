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
    ListNode* oddEvenList(ListNode* head) {
        // vector<int> v;
        // if(head == NULL || head->next == NULL) return head; 
        // ListNode* temp = head;
        // while(temp != NULL && temp->next != NULL){
        //     v.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp != NULL) v.push_back(temp->val);
        // temp = head->next;
        // while(temp != NULL && temp->next != NULL){
        //     v.push_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp != NULL) v.push_back(temp->val);
        // temp = head; int idx =0;
        // while(temp != NULL){
        //     temp->val = v[idx++];
        //     temp = temp->next;
        // }
        // return head;


        if(head == nullptr || head->next ==nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head->next; 
        ListNode* evenid = even;
        while(even != nullptr && even->next != nullptr){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;  even = even->next;
        }
        odd->next = evenid;
        return head;
    }
};