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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left==right || head== NULL  || head->next ==NULL) return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;

        ListNode *lprev=dummy;
        ListNode *curr=head;

        for(int i=1;i<left;i++){
            lprev=lprev->next;
            curr=curr->next;
        }

        ListNode *subLisHead=curr;
        ListNode *prev=NULL;
        for(int i=0;i<=(right-left);i++){
            ListNode *front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }

        lprev->next=prev;
        subLisHead->next=curr;

        return dummy->next;

    }
};