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
 // https://leetcode.com/problems/maximum-depth-of-binary-tree/
 // Time Complexity- O(h)  where h is the height of the tree
class Solution {
public:
    int dfs(TreeNode* root, int height){
        if(!root) return height;
        return max(dfs(root->left,height+1),dfs(root->right,height+1)); //return maximum height of left and right sub tree
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(dfs(root->left,1),dfs(root->right,1));
    }
};