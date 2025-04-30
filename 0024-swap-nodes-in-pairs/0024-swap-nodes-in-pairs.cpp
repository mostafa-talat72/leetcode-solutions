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
    ListNode* swapPairs(ListNode* head) {
	ListNode* dummy = new ListNode();
	ListNode* ret = dummy;
	while (head)	{
		int tmp = head->val;
		int next = -1;
		if(head->next){
			next = head->next->val;
		}
		if(next!=-1)
		{
			dummy->next = new ListNode(next);
			dummy = dummy->next;
			dummy->next = new ListNode(tmp);
            dummy = dummy->next;
			head = head->next->next;
		}else
		{
			dummy->next = new ListNode(tmp);
			head = head->next;
		}
	}
	return ret->next;
}
};