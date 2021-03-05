struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		vector<double> averageOfLevels(TreeNode *root)
		{
			vector<double> res;
			if(root == NULL)
				return res;
			
			queue<TreeNode*> q;
			q.push(root);
			q.push(NULL);
			
			double levelsum=0;
			int count=0;
			
			while(!q.empty())
			{
				TreeNode *temp = q.front();
				q.pop();
				
				if(temp==NULL)
				{
					res.push_back(levelsum/count);
					levelsum=0;
					count=0;
					
					if(!q.empty())
						q.push(NULL);
				}
				
				else
				{
					levelsum+=temp->val;
					count++;
					if(temp->left)
						q.push(temp->left);
					if(temp->right)
						q.push(temp->right);
				}
			}
			return res;
		}
};
