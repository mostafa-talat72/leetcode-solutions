class Solution {
public:
int Ceil(int num, int div) { return (num + div - 1) / div; }

    
int snakesAndLadders(vector<vector<int>>& board)
{
    int n = board.size();
    queue<pair<int,int>> q;
    vector<int> visited(n * n + 1, INT_MAX);
    q.push({1, 0});
    visited[1] = 0;
    int moves = INT_MAX;
    while (!q.empty())
    {
        auto [cell, steps] = q.front();
        q.pop();
        
        if (visited[cell] < steps)
            continue;
        if (cell == n * n)
        {
            moves = min(moves, steps);
            continue;
        }
        for (int i = 1; i <= 6; ++i)
        {
            int nextCell = cell + i;
            if (nextCell > n * n)
                continue;
            int row = Ceil(nextCell, n) - 1;
            int col = (nextCell - 1) % n;
            if (row & 1)
                col = n - 1 - col;
            row = n - 1 - row; 
            if (board[row][col] != -1)
                nextCell = board[row][col];
            if (visited[nextCell] <= steps + 1)
                continue;
            visited[nextCell] = steps + 1;
            q.push({nextCell, steps + 1});
        }
    }
    return moves == INT_MAX ? -1 : moves;
}
};