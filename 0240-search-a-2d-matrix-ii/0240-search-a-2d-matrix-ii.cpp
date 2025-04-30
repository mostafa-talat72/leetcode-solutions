class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	for(int i=0;i<matrix.size();i++){
		if(target>=matrix[i][0] && target<=matrix[i][matrix[i].size()-1]){
			if (binary_search(matrix[i].begin(), matrix[i].end(), target))
				return true;
		}
	}
	return false;
}
};