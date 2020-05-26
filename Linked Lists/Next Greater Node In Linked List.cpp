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

 //https://leetcode.com/problems/next-greater-node-in-linked-list/
 //Time Complexity- O(N), N = number of elements in list

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        if(head==NULL) return vals;
        while(head!=NULL){                          //Pushing every value in list to array
          vals.push_back(head->val);
          head=head->next;
        }
        stack<int> s;
        vector<int> ans(vals.size());               //Traversing from right to left
        for(int i=vals.size()-1;i>=0;i--){
           while(!s.empty() && s.top()<=vals[i]) s.pop(); //Popping the stack until we find the number greater than it's value
           ans[i]=s.empty() ? 0 : s.top();                 // If not found put zero
           s.push(vals[i]);
        }
        return ans;
    }
};