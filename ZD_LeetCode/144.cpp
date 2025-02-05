/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> A;
        stack<TreeNode*> s;
        if (root != 0)
            s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            A.push_back(p->val);
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
        return A;
    }
};
