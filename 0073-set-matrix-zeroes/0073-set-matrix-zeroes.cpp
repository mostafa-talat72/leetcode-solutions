class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    

    set<int> row, column;
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
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[it][i] = 0;
    }
    for (auto it : column)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][it] = 0;
    }

}
};