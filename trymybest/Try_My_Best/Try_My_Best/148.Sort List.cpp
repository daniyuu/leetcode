#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head-> next == nullptr) {
            return head;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(head);
        return mergeTwoLists(l1, l2);
    }
    
    
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        
        ListNode dummy(-1);
        ListNode *p = &dummy;
        
        for (; l1 != nullptr && l2 != nullptr; p = p->next) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        
        p->next = l1 != nullptr ? l1:l2;
        
        return dummy.next;
    }
};