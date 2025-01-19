/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *list1, ListNode *list2) {

        if (list1 == NULL || list2 == NULL) return NULL;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while (t1 != t2) {
            // Switch to the head of the other list when reaching the end
            t1 = (t1 == NULL) ? list2 : t1->next;
            t2 = (t2 == NULL) ? list1 : t2->next;
        }

        // Either return the intersection node or NULL if no intersection
        return t1;
    }
};