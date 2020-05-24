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

 //https://leetcode.com/problems/add-two-numbers-ii/
// Time Complexity- O(max(n,m))  where n and m are the lengths of the list

 // same logic is applied as Add two numbers problem, as the list is in reversed order we can make use of stack

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;     // If any of the numbers is null return the ohter list
        if(l2==NULL) return l1;
        stack<int> s1,s2;           //Pushing the lists in two separate stacks for using the list in reverse order
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode* ans = new ListNode();
        int num=0,carry=0;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){num+=s1.top();s1.pop();}
            if(!s2.empty()){num+=s2.top();s2.pop();}
            num+=carry;
            carry=0;
            if(num>9) {num-=10;carry=1;}
            ListNode* temp = new ListNode();
            ans->val=num;                       //Adding the new list containing the sum
            temp->next=ans;
            ans=temp;
            num=0;
        }
        if(carry){                              //Check if carry is still present or not, If yes, Add 1
            ListNode* temp = new ListNode();
            ans->val=carry;
            temp->next=ans;
            ans=temp;
        }
        return ans->next;
    }
};