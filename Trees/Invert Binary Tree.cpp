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
 // https://leetcode.com/problems/invert-binary-tree/
  // Time Complexity- O(N)  where N is the number of nodes in a tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(root->right) root->right = invertTree(root->right);
        if(root->left) root->left  = invertTree(root->left);
        if(root->left || root->right) swap(root->right, root->left);
        return root;
    }
};