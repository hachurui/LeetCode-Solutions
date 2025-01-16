/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyhead = new ListNode();
        ListNode* mergedList = dummyhead;
        while(list1!=nullptr || list2!=nullptr)
        {
            if(list1==nullptr)//if reached the end of list1, push the rest of list2
            {
                mergedList->next = list2;
                list2=list2->next;
            }
            else if(list2==nullptr)//if list2 finished, push the rest of list1
            {
                mergedList->next = list1;
                list1=list1->next;
            }
            else //if both lists still have elements
            {
                if(list1->val < list2->val)
                {
                    mergedList->next = list1;
                    list1=list1->next;
                }
                else
                {
                    mergedList->next = list2;
                    list2 = list2->next;
                }
            }
            mergedList = mergedList->next; //go to next of listsand start loop again
        }
        return dummyhead->next;
    }
};