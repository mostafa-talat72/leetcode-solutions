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
class FindElements {
private:
	unordered_map<int, int>arr;
	void generateNode(TreeNode* root) {
		if (!root)
			return;
		arr[root->val]++;
		if (root->left) {
			root->left->val = root->val * 2 + 1;
		}
		if (root->right) {
			root->right->val = root->val * 2 + 2;
		}
		generateNode(root->left);
		generateNode(root->right);
	}
public:
	FindElements(TreeNode* root) {
		root->val = 0;
		generateNode(root);
	}

	bool find(int target) {
		return arr[target];
	}
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */