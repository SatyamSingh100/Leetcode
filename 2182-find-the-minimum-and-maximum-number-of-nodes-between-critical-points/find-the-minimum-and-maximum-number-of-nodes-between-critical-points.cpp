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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        ListNode* first = head;
        ListNode* second = head->next;
        int cnt = 2;
        vector<int> index;
        while (second->next != NULL)
        {
            if (second->val < first->val && second->val < second->next->val) index.push_back(cnt);
            if (second->val > first->val && second->val > second->next->val) index.push_back(cnt);
            second = second->next;
            first = first->next;
            cnt++;
        }
        //sort(index.begin(), index.end());
        if (index.size() <= 1) return {-1, -1};
        int n = index.size();
        int maxDis = index[n-1] - index[0];
        int minDis = 1e9;
        for (int i = 1; i < n; i++) minDis = min(minDis, index[i] - index[i-1]);
        return {minDis, maxDis};
    }
};