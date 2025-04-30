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
   ListNode* sortList(ListNode* head) {
	vector<int>v;
	ListNode* cur = new ListNode();
	ListNode* res = cur;
	while (head) {
		v.push_back(head->val);
		head = head->next;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cur->next = new ListNode(v[i]);
		cur = cur->next;
	}
	return res->next;
}
};