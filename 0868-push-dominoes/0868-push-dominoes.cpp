class Solution {
public:
    string pushDominoes(string dominoes) 
{ int n = dominoes.size();
    vector<int> pre(n + 1, 0);
    int last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (dominoes[i] == '.')
            continue;
        if (dominoes[i] == 'L')
        {
            if (last == -1)
            {
                pre[0] += -1;
                pre[i + 1] += 1;
            }
            else if (last > -1 && dominoes[last] == 'R')
            {
                int mid = (i - last) / 2;
                pre[i + 1] += 1;
                pre[i - mid] += -1;
                pre[last + mid + 1] += -1;
			}
            else
            {
                pre[i + 1] += 1;
                pre[last + 1] += -1;
            }
           
        }
        else if (dominoes[i] == 'R')
        {
            if (last == -1 || dominoes[last] == 'L')
            {
                pre[i] += 1;
            }
        }
        last = i;

    }
    for (int i = 1; i < n ; ++i)
    {
        pre[i] += pre[i - 1];
    }
    for (int i = 0; i < n; ++i)
    {
        if (pre[i] > 0)
            dominoes[i] = 'R';
        else if (pre[i] < 0)
            dominoes[i] = 'L';
    }   
    return dominoes;
}

};