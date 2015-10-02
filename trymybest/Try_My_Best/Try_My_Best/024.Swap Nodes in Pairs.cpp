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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode dummy(-1);
        dummy.next = head;
        
        
        for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next; next; prev = cur,cur = cur->next, next = cur? cur->next: nullptr) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        
        return dummy.next;
    }
};


//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        ListNode *p;
//        while (p && p->next) {
//            swap(p->val,p->next->val);
//            p = p->next->next;
//        }
//        return head;
//    }
//};