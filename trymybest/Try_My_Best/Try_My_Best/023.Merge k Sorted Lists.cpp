#include <iostream>
#include <vector>
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
private:
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int sz = lists.size();
        if (sz == 0)
            return NULL;
        
        while (sz > 1) {
            int k = (sz + 1) / 2;
            for (int i = 0; i < sz / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            sz = k;
        }
        return lists[0];
    }
};