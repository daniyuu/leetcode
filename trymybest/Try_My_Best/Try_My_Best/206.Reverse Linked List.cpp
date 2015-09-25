#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution {
public:
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
};

//int main(){
//
//}