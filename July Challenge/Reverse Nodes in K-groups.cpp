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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int cnt=0;
        while(curr)
        {
            cnt++;
            if(cnt==k)
            {
                break;
            }
            curr = curr->next;
        }
        if(cnt<k)
        {
            return head;
        }
        ListNode *next = reverseKGroup(curr->next, k);
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        ListNode *c = head;
        for(int i=0;i<k;i++)
        {
            temp = c->next;
            c->next = prev;
            prev = c;
            c = temp;
        }
        head->next = next;
        return prev;

    }
};
