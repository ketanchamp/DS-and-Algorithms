/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

 //https://leetcode.com/problems/linked-list-in-binary-tree/
 // Time Complexity- O(N) where N is the no. of nodes in the tree


class Solution {
public:
    bool check(TreeNode* root, ListNode* head){
        if(root->val != head->val) return false;
        if(head->next == NULL)  return true;  //If head is at end , then we have fin the total list, return true
        if(root->left  != NULL) if(check(root->left,  head->next)) return true; // check for all nodes left and right continuously
        if(root->right != NULL) return check(root->right, head->next);
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;   // If head of list is NULL return true
        if(root == NULL) return false;  // If tree is NULL and list is not null then return false
        if(check(root, head)) return true; // Check funtion returns true if list is present form starting node
        if(root->left  != NULL)    if(isSubPath(head, root->left)) return true; //Check for all nodes in the tree
        if(root->right != NULL)    if(isSubPath(head, root->right)) return true;
        return false;
    }
};