
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0); //will be the dummy node for beginning of sum linked list
        ListNode* currNode = head; //tracks what node of sum linked list we're on
        int x; //will be assigned l1's value (or 0 if no value)
        int y; //x but for l2
        int carryover = 0; //since each node only contains single digit, carryover is for when a sum >= 10 and added to next sum
        int sum; //will be x + y or l1->val + l2->val
        while(l1 != nullptr || l2 != nullptr || carryover != 0)
        {
            x = l1 != nullptr ? l1->val : 0;
            y = l2 != nullptr ? l2->val : 0;
            sum = x + y + carryover;
            //gotta be mindful if sum >= 10; probably just straight up set next node's value to sum%10 and then carryover to sum/10; no need for if statement?
            currNode->next = new ListNode(sum%10);
            carryover = sum/10;
            //get next nodes to prepare next loop
            currNode = currNode->next;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }
        //return the second node of the list since the head is a dummy node. Good practice? Idk.
        return head->next;
    }
};