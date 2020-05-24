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

 // https://leetcode.com/problems/add-two-numbers/
// Time Complexity- O(max(n,m))  where n and m are the lengths of the list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;   // If any of the numbers is null return the ohter list
        if(l2==NULL) return l1;
        int num=0,carry=0;
        ListNode* head= new ListNode();
        ListNode* sum=head;
        while(l1!=NULL||l2!=NULL){
               num=0;                       //digit sum variable
               if(l1==NULL){
                   num=l2->val;
               }
               else if(l2==NULL){
                   num=l1->val;
               }
               else{
                   num=l1->val+l2->val;
               }
            num+=carry;                     //If carry present previously add it as well
            carry=0;
            if(num>9){
                num-=10;                    //Store the sum after removing the carry
                carry=1;
            }
            ListNode* temp=new ListNode(num);
            sum->next=temp;
            sum=sum->next;                  //Adding the new list containing the sum
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        if(carry==1){                       //Check if carry is still present or not, If yes, Add 1
          ListNode* temp=new ListNode(1);
          sum->next=temp;
        }
        return head->next;
    }
};