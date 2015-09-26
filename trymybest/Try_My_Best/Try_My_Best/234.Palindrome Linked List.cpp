/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *pre = head;
        ListNode *p = head->next;
        
        pre->next = NULL;
        ListNode *nxt;
        while (p != NULL) {
            nxt = p->next;
            p->next = pre;
            pre = p;
            p = nxt;
        }
        
        return pre;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast) {
            slow->next = reverseList(slow->next);
            slow = slow->next;
        }else{
            slow = reverseList(slow);
        }
        
        while (slow) {
            if (head->val != slow->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        
        
        return true;
    }
};