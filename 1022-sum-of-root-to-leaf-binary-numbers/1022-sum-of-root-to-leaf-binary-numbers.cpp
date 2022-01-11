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
    int sumRootToLeaf(TreeNode* node, int pre=0) {
        if (!node->left and !node->right) 
			return pre * 2 + node->val;
        int ans = 0;
        if (node->left)
			ans += sumRootToLeaf(node->left, pre * 2 + node->val);
        if (node->right)
			ans += sumRootToLeaf(node->right, pre * 2 + node->val);
        return ans;
    }
};