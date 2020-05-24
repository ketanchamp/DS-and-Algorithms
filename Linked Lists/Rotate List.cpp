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

//https://leetcode.com/problems/rotate-list/

// Time Complexity- O(n) using counting the nodes in the list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* ans = head;
        ListNode* last = new ListNode();
        int nodes=0;                            //Count the number of nodes in the list
        while(ans!=NULL){
            nodes++;
            if(ans->next==NULL) last=ans;
            ans=ans->next;
        }
        if(nodes==0||nodes==1) return head;
        last->next=head;
        k=k%nodes;                              //If k is greater than nodes present, this operation will reduce the number of steps required
        nodes-=k;                               //as the rotation will repeat after every full list traversal
        while(--nodes){
            head=head->next;
        }                                       //Break the chain at the kth node from right, point it to null
        ans=head->next;
        head->next=NULL;                        //Make kth node from right the head node
        return ans;

    }
};

// Time Complexity- O(K) without counting the nodes in the lists
//Note: This might give TLE for high values of K
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(k==0||head==NULL||head->next==NULL) return head;
        while(k--){                                         // make fast pointer start from kth node and slow from 1st node
            if(fast->next!=NULL) fast=fast->next;
            else fast=head;
        }
        while(fast->next!=NULL){                            //Untill fast node points to null
          slow=slow->next;
          fast=fast->next;
        }
        fast->next=head;                                    //break the chain from that point, and slow->next will be our new head node
        head=slow->next;
        slow->next=NULL;
        return head;

    }
};