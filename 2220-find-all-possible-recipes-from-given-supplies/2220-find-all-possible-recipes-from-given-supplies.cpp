class Solution {
public:
    
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
	unordered_map<string, int>inDegree;
	unordered_map<string, vector<string>>adj;
	for (int i = 0; i < ingredients.size(); i++) {
		for (string it : ingredients[i])
			adj[it].push_back(recipes[i]);

		inDegree[recipes[i]] = ingredients[i].size();
	}

	vector<string>ans;
	while (supplies.size()) {
		string top = supplies.back();
		supplies.pop_back();
		for (string recipe : adj[top]) {
			inDegree[recipe]--;
			if (!inDegree[recipe]) {
				supplies.push_back(recipe);
				ans.push_back(recipe);
			}
		}

	}
	return ans;
}
};