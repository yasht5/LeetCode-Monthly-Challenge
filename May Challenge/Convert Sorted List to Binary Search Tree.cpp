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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *lsit;
    int length(ListNode *head)
    {
        int sz = 0;
        while(head)
        {
            sz++;
            head = head->next;
        }
        return sz;
    }
    TreeNode *generate(int n)
    {
        if(!n)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(0);
        root->left = generate(n/2);
        root->val = lsit->val;
        lsit = lsit->next;
        root->right = generate(n - n/2 -1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        this->lsit = head;
        int n = length(head);
        return generate(n);
    }
};
