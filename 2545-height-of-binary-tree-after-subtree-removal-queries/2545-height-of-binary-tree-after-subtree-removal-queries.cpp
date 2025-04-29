class Solution {
public:
	int dfs(int level, TreeNode* root, unordered_map<int, priority_queue<pair<int, pair<int, int>>>>& level_mx, unordered_map<int, int>& level_nums) {
		if (!root)return level;
		int left = 0, right = 0;
		right = dfs(level + 1, root->right, level_mx, level_nums);
		left = dfs(level + 1, root->left, level_mx, level_nums);

		level_mx[level + 1].push({ max(right,left) - 1,{level - 1,root->val } });
		level_nums[root->val] = level + 1;
		return max(left, right);

	}
	vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
		unordered_map<int, priority_queue<pair<int, pair<int, int>>>>level_mx;
		unordered_map<int, int>level_nums;
		dfs(0, root, level_mx, level_nums);
		for (auto& it : queries)
		{
				
			if (!level_mx[level_nums[it]].empty() && level_mx[level_nums[it]].top().second.second != it)
			{
				it = level_mx[level_nums[it]].top().first;
			}
			else  {
				auto top = level_mx[level_nums[it]].top();
				int level = level_nums[it];
				level_mx[level_nums[it]].pop();
				if (!level_mx[level_nums[it]].empty())
				{
					it = max(level_mx[level_nums[it]].top().first, top.second.first);
				}
				else
					it = top.second.first;
				level_mx[level].push(top);
			}
			

		}
		return queries;
	}
};