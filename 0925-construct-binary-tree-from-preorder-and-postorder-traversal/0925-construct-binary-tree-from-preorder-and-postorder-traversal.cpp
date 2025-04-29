/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
	TreeNode* root = new TreeNode(preorder[0]);
	stack<TreeNode*> s;
	s.push(root);
	int i = 1, j = 0;
	while (i < preorder.size()) {
		TreeNode* childRoot = new TreeNode(preorder[i]);
		if (s.top()->left == nullptr)
			s.top()->left = childRoot;
		else
			s.top()->right = childRoot;
		s.push(childRoot);
		while (!s.empty() && j<postorder.size() && s.top()->val == postorder[j]) {
			s.pop();
			j++;
		}
		i++;
	}
	return root;
}
};