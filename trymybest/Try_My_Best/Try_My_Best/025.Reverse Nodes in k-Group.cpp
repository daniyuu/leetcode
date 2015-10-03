#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *next_group = head;
        for (int i = 0; i < k; ++i) {
            if (next_group) {
                next_group = next_group->next;
            }
            else{
                return head;
            }
        }
        
        ListNode *new_next_group = reverseKGroup(next_group, k);
        ListNode *prev = NULL;
        ListNode *cur = head;
        
        while (cur != next_group) {
            ListNode *next = cur->next;
            cur->next = prev ? prev: new_next_group;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};