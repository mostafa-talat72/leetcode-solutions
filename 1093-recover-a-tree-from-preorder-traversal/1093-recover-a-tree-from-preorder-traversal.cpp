class Solution {
private:
	unordered_map<int, vector<pair<TreeNode*, int>>>level;
	TreeNode* root = nullptr;
	void concat(string& dash, string& num) {
		level[dash.size()].push_back({ new TreeNode(stoi(num)) ,2 });
		if (dash.size() == 0) {
			root = level[dash.size()].back().first;
		}else
		{
			int& direction = level[dash.size() - 1].back().second;
			if (direction == 2) {
				direction = 1;
				level[dash.size() - 1].back().first->left = level[dash.size()].back().first;
			}
			else {
				direction = 0;
				level[dash.size() - 1].back().first->right = level[dash.size()].back().first;
				level[dash.size() - 1].pop_back();
			}
		}
		num = "";
		dash = "-";
	}

public:
	TreeNode* recoverFromPreorder(string traversal) {
		string dash = "", num = "";
		for (auto it : traversal) {
			if (it == '-' && !num.empty()) {
					concat(dash, num);
			}
			else if (it == '-')
				dash += it;
			else
				num += it;
		}
		concat(dash, num);
		return root;
	}
};