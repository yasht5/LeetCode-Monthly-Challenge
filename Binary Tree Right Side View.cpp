/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
 */
 
 struct TreeNode{
 	int x;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
	
	public:
		vector<int> rightSideView(TreeNode *root)
		{
			vector<int> res;
			if(root == NULL)
				return res;
			
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty())
			{
				int n = q.size();
				for(int i=0;i<n;i++)
				{
					TreeNode *temp = q.front();
					q.pop();
					if(i==n-1)
					{
						res.push_back(temp->val);
					}
					if(temp->left)
						q.push(temp->left);
					if(right->right)
						q.push(temp->right);
				}
			}
			return res;
		}
		
};
	
