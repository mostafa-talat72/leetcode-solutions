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
    int dfs(ListNode* root, int n) {
	if (!root) return 0;
	int ret = dfs(root->next, n) + 1;
	if(ret - 1 == n)
	{
		if(root->next)
		{
			root->next = root->next->next;
		}
		else
		{
			root->next = nullptr;
		}
	}
	return ret;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(dfs(head, n) == n)
	{
		head = head->next;
	}
	return head;
}
};