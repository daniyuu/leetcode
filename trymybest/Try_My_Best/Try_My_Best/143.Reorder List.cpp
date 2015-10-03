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
private:
    ListNode *reverse(ListNode *head){
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *prev = head;
        
        for (ListNode *curr = head->next, *next = curr->next; curr; prev = curr, curr = next, next = next? next->next: nullptr) {
            curr->next = prev;
        }
        head->next = nullptr;
        return prev;
        
    }
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return ;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        slow = reverse(slow);
        
        //merge
        ListNode *curr = head;
        
        while (curr->next) {
            ListNode *temp = curr->next;
            curr->next = slow;
            slow = slow->next;
            curr->next->next = temp;
            curr = temp;
        }
        
        curr->next = slow;
        
    }
};