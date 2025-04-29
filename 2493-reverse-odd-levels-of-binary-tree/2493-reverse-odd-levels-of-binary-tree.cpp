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
   void nodeLevel(TreeNode* root, int level, unordered_map<int, vector<TreeNode*>>& nodes) {
	if (!root)return;
	if (level & 1)
		nodes[level].push_back(root);
	nodeLevel(root->left, level + 1, nodes);
	nodeLevel(root->right, level + 1, nodes);

}
TreeNode* reverseOddLevels(TreeNode* root) {
	unordered_map<int, vector<TreeNode*>> nodes;
	int level = 0;
	nodeLevel(root, level, nodes);
	for (auto& node : nodes) {
		int i = 0, j = node.second.size() - 1;
		while (i < j) {
			swap(node.second[i]->val, node.second[j]->val);
			i++;
			j--;
		}
	}
	return root;
}
};