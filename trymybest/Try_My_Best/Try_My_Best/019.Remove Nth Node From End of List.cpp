#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) {
            return head;
        }
        
        int num = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            cur = cur->next;
            num++;
        }
        
        if (num == n) {
            ListNode *ret = head->next;
            delete head;
            return ret;
        }else{
            int m = num - n - 1;
            cur = head;
            while (m--) {
                cur = cur->next;
            }
            
            ListNode *ret = cur->next;
            cur->next = cur->next->next;
            delete ret;
            return head;
        }
    }
};