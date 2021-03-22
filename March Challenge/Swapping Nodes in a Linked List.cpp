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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> help;
        
        ListNode* t = head;
        while(t!=NULL)
        {
            help.push_back(t->val);
            t=t->next;
        }
        int n = help.size();
        swap(help[k-1], help[n-k]);
        
        ListNode *res;
        
        
        res = new ListNode(help[0]);
        ListNode* temp =res;
        for(int i=1;i<n;i++)
        {
            temp->next = new ListNode(help[i]);
            temp = temp->next;
        }
        return res;
        
    }
};
