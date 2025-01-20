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
    int getLen(ListNode *head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int len=getLen(head);
        k %= len;
        if(k==0) return head;

        ListNode *tail=head;
        while(tail->next != NULL){
            tail=tail->next;
        }
        tail->next=head;

        ListNode *tmp=head;
        ListNode *prev=NULL;
        int rotate=len-k-1;
        while(tmp && rotate > 0){
            tmp=tmp->next;
            rotate--;
        }
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
};