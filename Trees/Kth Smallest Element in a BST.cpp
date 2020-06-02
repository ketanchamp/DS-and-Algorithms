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
 // https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 // Time Complexity- O(h)  where h is the height of the binary search tree
  class Solution {
  public:
      int solve(TreeNode* root, int& k){ //k value passed by reference
          int x;
          if(root){
              x=solve(root->left, k);
              if(!k) return x;
              k--;
              if(!k) return root->val;
              return solve(root->right, k);
          }
          return 0;
      }
      int kthSmallest(TreeNode* root, int k) {
          return solve(root, k);
      }
  };