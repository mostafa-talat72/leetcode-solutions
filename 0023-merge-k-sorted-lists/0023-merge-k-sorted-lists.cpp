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
   ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* ret = new ListNode();
	ListNode* cur = ret;
	while(lists.size()) {
		int idx = -1;
		for (int i = 0; i < lists.size(); i++) {
			if ((idx == -1 && lists[i]) || (lists[i] && lists[i]->val < lists[idx]->val))idx = i;
		}
		if (idx == -1)break;
		cur->next = lists[idx];
		cur = cur->next;
		lists[idx] = lists[idx]->next;
	}
	return ret->next;
}
};