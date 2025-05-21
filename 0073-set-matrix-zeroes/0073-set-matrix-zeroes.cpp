class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> row, column;
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (!matrix[i][j])
            {
                row.insert(i);
                column.insert(j);
            }
        }
    }
    for (auto it : row)
    {
        fill(matrix[it].begin(), matrix[it].end(), 0);
    }
    for (auto it : column)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][it] = 0;
    }
}
};