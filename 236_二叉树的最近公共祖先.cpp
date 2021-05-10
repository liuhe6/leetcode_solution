TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p , q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
