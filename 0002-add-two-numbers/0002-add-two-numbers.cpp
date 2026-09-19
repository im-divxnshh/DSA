class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // fake head, so we never handle "first node" separately
        ListNode* tail = &dummy;    // always points to the last node of the result
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) { sum += l1->val; l1 = l1->next; }
            if (l2 != nullptr) { sum += l2->val; l2 = l2->next; }

            carry = sum / 10;                    // 0 or 1
            tail->next = new ListNode(sum % 10); // digit to write down
            tail = tail->next;                   // move tail forward
        }
        return dummy.next;          // skip the fake head
    }
};