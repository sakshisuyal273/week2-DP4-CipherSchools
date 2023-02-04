//inorder traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(true) {
            if(node!= NULL) {
                s.push(node);
                node=node->left;
            }
            else {
                if(s.empty()==true) break;
                node=s.top();
                s.pop();
                v.push_back(node->val);
                node=node->right;
            }
        }
        return v;
    }
};