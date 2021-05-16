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
    int ans  = 0;
    set<TreeNode*> s;
    
    int minCameraCover(TreeNode* root) {
        ans = 0;
        s.insert(NULL);
        dfs(root, NULL);
        return ans;
    }
    
    void dfs(TreeNode *curr, TreeNode* par)
    {
        if(curr)
        {
            dfs(curr->left, curr);
            dfs(curr->right, curr);
        
            if(!par && s.find(curr) == s.end() || s.find(curr->left) == s.end() || s.find(curr->right) == s.end())
            {
                ans++;
                s.insert(curr);
                s.insert(par);
                s.insert(curr->left);
                s.insert(curr->right);
                
            }
            
        }
        
    }
    
};
