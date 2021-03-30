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
    int idx = 0;
    vector<int> res;
    
    void dfs(TreeNode *root, vector<int> voyage)
    {
        if(!root || (res.size() && res[0]==-1))
        {
            return;
        }
        if(root->val != voyage[idx++])
        {
            res = {-1};
        }
       
        else if(root->left && root->left->val != voyage[idx])
        {
            res.push_back(root->val);
            dfs(root->right, voyage);
            dfs(root->left, voyage);
            
        }
        else
        {
            dfs(root->left, voyage);
            dfs(root->right, voyage);
            
        }
            
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        dfs(root, voyage);
        return res;
    }
};
