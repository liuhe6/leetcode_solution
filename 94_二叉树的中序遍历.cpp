// 递归方法
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
}
// 使用栈的方法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root || stk.size()) {
            while(root) {
                stk.push(root);
                root = root->left;
            }
            if(stk.size()) {
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};