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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            root = newNode;
        }
        int level=0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 2});
        while(!s.empty())
        {
            pair<TreeNode*, int> p = s.top();
            s.pop();
            TreeNode *temp = p.first;
            level = p.second;
            
            if(level == d)
            {
                TreeNode *newNode1 = new TreeNode(v);
                TreeNode *newNode2 = new TreeNode(v);
                newNode1->left = temp->left;
                newNode2->right = temp->right;
                temp->left = newNode1;
                temp->right = newNode2;
                
            }
            else
            {
                if(temp->left)// && temp->left->val !=0)
                {
                    s.push({temp->left, level+1});
                }
                if(temp->right)// && temp->right->val !=0)
                {
                    s.push({temp->right, level+1});
                }
            }
        }
        
        return root;
    }
};
