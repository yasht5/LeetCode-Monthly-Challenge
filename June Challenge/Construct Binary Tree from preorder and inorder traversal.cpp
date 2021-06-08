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
    map<int, int> mp;
    int pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        pos = 0;
        return solve(inorder, preorder, 0, inorder.size()-1);
    }
    
    TreeNode *solve(vector<int>&in, vector<int>&pre, int s, int e)
    {
        if(s>e)
        {
            return NULL;
        }
        TreeNode *curr = new TreeNode(pre[pos]);
        pos++;
        if(s==e)
        {
            return curr;
        }
        int idx = mp[curr->val];
        curr->left = solve(in, pre, s, idx-1);
        curr->right = solve(in, pre, idx+1, e);
        return curr;
    }
};
