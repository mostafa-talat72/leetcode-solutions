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
    ListNode* reverseKGroup(ListNode* head, int k) {
	vector<int>v;
	ListNode* temp =new ListNode();
	ListNode* ans = temp;
	while(head){
		v.push_back(head->val);
		if(v.size() == k){
			reverse(v.begin(), v.end());
			for (int i = 0; i < k; i++)
			{
				temp->next = new ListNode(v[i]);
				temp = temp->next;
			}
			v.clear();
		}
		head = head->next;
	}

	if(v.size() > 0){
		for (int i = 0; i < v.size(); i++)
		{
			temp->next = new ListNode(v[i]);
			temp = temp->next;
		}
	}
	return ans->next;
}
};