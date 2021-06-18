struct tree{
    int start, end, sum;
    tree *left;
    tree *right;
    
    tree(int a, int b) : start(a), end(b), sum(0), left(NULL), right(NULL){}
};

class NumArray {
public:
    tree* root;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = build(nums, 0, n-1);
    }
    
    void update(int index, int val) {
        modifyTree(index, val, root);
    }
    
    int sumRange(int left, int right) {
        return sumcal(left, right, root);
    }
    
    tree* build(vector<int>&v, int start, int end)
    {
        if(start > end)
        {
            return NULL;
        }
        tree *root = new tree(start, end);
        if(start == end)
        {
            root->sum = v[start];
            return root;
        }
        int mid = start + (end - start)/2;
        root->left = build(v, start, mid);
        root->right = build(v, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    int modifyTree(int i, int val, tree* root)
    {
        if(!root)
        {
            return 0;
        }
        int d;
        if(root->start == i && root->end == i)
        {
            d = val - root->sum;
            root->sum = val;
            return d;
        }
        int mid = (root->start + root->end)/2;
        
        if(i> mid)
        {
            d = modifyTree(i, val, root->right);
        }
        else
        {
            d = modifyTree(i, val, root->left);
        }
        root->sum = root->sum + d;
        return d;
    }
    
    int sumcal(int i, int j, tree* root)
    {
        if(!root)
        {
            return 0;
        }
        if(root->start == i && root->end == j)
        {
            return root->sum;
        }
        int mid = (root->start + root->end)/2;
        if(i>mid)
        {
            return sumcal(i, j, root->right);
        }
        if(j<=mid)
        {
            return sumcal(i, j, root->left);
        }
        return sumcal(i, mid, root->left) + sumcal(mid+1, j, root->right);
    };
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
