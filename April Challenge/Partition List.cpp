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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less=NULL;
        ListNode *more=NULL;
        ListNode *t1=NULL;
        ListNode *t2=NULL;
        if(!head)
        {
            return NULL;
        }
        ListNode *curr = head;
        while(curr)
        {
            if(curr->val < x)
            {
                if(!less)
                {
                    less = new ListNode(curr->val);
                    t1 = less;
                }
                else
                {
                    t1->next = new ListNode(curr->val);
                    t1 = t1->next;
                }
            }
            else
            {
                if(!more)
                {
                    more = new ListNode(curr->val);
                    t2 = more;
                }
                else
                {
                    t2->next = new ListNode(curr->val);
                    t2 = t2->next;
                }
            }
            curr = curr->next;
        }
        if(!more)
            return less;
        if(!less)
            return more;
        t1->next = more;
        return less;
    }
};
