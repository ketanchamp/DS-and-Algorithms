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

 //https://leetcode.com/problems/merge-k-sorted-lists/
 //Time Complexity- O(nlog(n)) n = number of elements in all of the k list
 // log(n) for insertion in min_heap(min_priority queue)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;                         //Max_priority_queue (multipying every number with -1 to amke it Min_priority_queue)
        ListNode * ans = new ListNode();
        for(int i=0;i<lists.size();i++){
          while(lists[i]!=NULL){ pq.push(-1*(lists[i]->val));lists[i]=lists[i]->next;}
        }
        ListNode* head=ans;                             //Adding new node from priority_queue , so that the list is now sorted
        while(!pq.empty()){
            ListNode* temp = new ListNode(-1*pq.top());
            ans->next=temp;
            ans=ans->next;
            pq.pop();
        }
        return head->next;
    }
};