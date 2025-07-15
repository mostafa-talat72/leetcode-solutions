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
    int getDecimalValue(ListNode* head) {
	
	int ans = 0;
    string s = "";
    while (head)
    {
		s += to_string(head->val);
		head = head->next;
    }
	for (int i = 0; i < s.size(); i++)
    {
		ans += (s[i] - '0') * pow(2, s.size() - 1 - i);
    }
    cout << ans << "\n";

	return ans;

}
};