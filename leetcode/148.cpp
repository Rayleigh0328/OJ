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
    ListNode* merge_sort(ListNode* first)
    {
        if (first->next == NULL) return first;
    
        // get length
        int len = 1;
        ListNode* tail2 = first;
        while (tail2->next != NULL)
        {
            tail2 = tail2->next;
            ++len;
        }
        
        // get mid
        int cnt = 1;
        ListNode* tail1 = first;
        while (cnt < len /2)
        {
            tail1 = tail1->next;
            ++cnt;
        }
        ListNode* first2 = tail1->next;
        tail1->next = NULL;
        
        //cout << first->val << " " << first2->val << endl;
        // recursion
        ListNode* h1 = merge_sort(first);
        ListNode* h2 = merge_sort(first2);
        
        // merge two sub-list
        ListNode *sen = new ListNode(-1);
        ListNode *tail = sen;
        while (h1 != NULL || h2 != NULL)
        {
            if (h1 == NULL || (h2!=NULL && h2->val <= h1->val))
            {
                //cout << "append: " << h2->val << endl;
                tail->next = h2;
                tail = tail->next;
                h2 = h2->next;
                tail->next = NULL;
                continue;
            }
            if (h2 == NULL || (h1!=NULL && h1->val <  h2->val))
            {
                //cout << "append: " << h1->val << endl;
                tail->next = h1;
                tail = tail->next;
                h1 = h1->next;
                tail->next = NULL;
                continue;
            }
        }
        
        ListNode* result = sen->next;
        delete sen;
        return result;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        if (head == NULL) return head;
        return merge_sort(head);
    }
};