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
    struct min_of_list
    {
        int val;
        int list_num;
        
        min_of_list(int v, int l)
        {
            val = v;
            list_num = l;
        }
        
        bool operator<(const min_of_list& other) const
        {
            if (val < other.val) return true;
            if (val > other.val) return false;
            return list_num < other.list_num;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        set<min_of_list> s;
        s.clear();
        for (int i=0;i<lists.size();++i)
            if (lists[i] != NULL)
            {
                // cout << i << endl;
                s.insert(min_of_list(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        // cout << lists.size() << endl;
        // cout << s.size() << endl;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (!s.empty())
        {
            set<min_of_list>::iterator it = s.begin();
            
            // cout << s.size() << " " <<  it->val << " " << it->list_num << endl;
            
            int v = it->val;
            int pos = it->list_num;
            
            // erase min value
            s.erase(it);
            
            // update if not empty
            if (lists[pos] != NULL)
            {
                s.insert(min_of_list(lists[pos]->val,pos));
                lists[pos] = lists[pos]->next;
            }
            
            // update result
            tail -> next = new ListNode(v);
            tail = tail->next;
        }
        
        return head->next;
    }
};

