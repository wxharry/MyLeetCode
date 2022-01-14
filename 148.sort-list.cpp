/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
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
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *slow=head, *fast=head->next, *l1, *l2;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        l2 = sortList(slow->next);
        slow->next = nullptr;
        l1 = sortList(head);
        return mergeList(l1, l2);
    };
};
// @lc code=end

