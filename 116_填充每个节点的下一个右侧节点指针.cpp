
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        auto t = root;
        while(root->left) {
            for(auto p = root; p; p=p->next) {
                p->left->next = p->right;
                if(p->next) {
                    p->right->next = p->next->left;
                }
            }
            root = root->left;
        }
        return t;
    }
};
