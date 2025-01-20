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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1,*t2=l2, *result = new ListNode(-1), *tmp = result;
        int c=0;
        while(t1 != NULL || t2 != NULL){
            int ans=c;
            if(t1) ans +=t1->val;
            if(t2) ans+=t2->val;

            ListNode *n=new ListNode(ans%10);
            tmp->next=n;
            tmp=tmp->next;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
            c=ans/10;
        }
        if(c){
            ListNode *n= new ListNode(c);
            tmp->next=n;
        }

        return result->next;
    }
};