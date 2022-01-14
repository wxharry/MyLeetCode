/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next)
        {
            return nullptr;
        }
        
        ListNode *r, *pre;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        pre=dummy;
        r=dummy;
        for (int i = 0; i < n; ++i)
        {
            r=r->next;
        }
        while (r->next)
        {
            pre = pre->next;
            r = r->next;
        }
        ListNode* del = pre->next;
        pre->next = pre->next->next;
        delete del;

        return dummy->next;
        
    }
};
// @lc code=end

