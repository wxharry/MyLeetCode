/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newHead = nullptr;
        ListNode* p;
        while (head)
        {
            p = head;
            head = head->next;
            p->next = newHead;
            newHead = p;
        }
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast=head, *slow=head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = fast ? slow->next : slow;
        ListNode* q = reverseList(slow);
        ListNode* p=head;
        while (p && q)
        {
            if (p->val != q->val)
            {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
// @lc code=end

