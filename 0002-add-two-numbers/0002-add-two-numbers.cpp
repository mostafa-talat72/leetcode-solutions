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
      
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* ret = new ListNode();
	ListNode* ans = ret;
	int carry = 0;
	while(l1 || l2) {
		if(l1 && l2)
		{
			carry = (l1->val + l2->val + carry);
			l1 = l1->next;
			l2 = l2->next;
		}else if(l1)
		{
			carry = (l1->val + carry);
			l1 = l1->next;
		}else{
			carry = (l2->val + carry);
			l2 = l2->next;
		}
		ret->val = (carry) % 10;
		carry = carry / 10;
		if (l1 || l2) {
			ret->next = new ListNode();
			ret = ret->next;
		}
	}
	if (carry) {
		ret->next = new ListNode(carry);
	}
	return ans;
}
};