/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans;
        ListNode* pt1 = l1, *pt2 = l2;
        ListNode* ptn = &ans;
        int addUnit=0;
        while (pt1|| pt2)
        {
            int unit=addUnit;
            if (pt1){
                unit+=pt1->val;
                pt1 = pt1->next;
            }
            if (pt2) {
                unit+=pt2->val;
                pt2 = pt2->next;
            }
            ListNode* nt = new ListNode(unit%10);
            addUnit = unit/10;
            ptn->next = nt;
            ptn = ptn->next;
        }
        if (addUnit)
        {
            ListNode* nt = new ListNode(1);
            ptn->next = nt;
            ptn = ptn->next;
        }
        
        return ans.next;
    }
};
// @lc code=end

