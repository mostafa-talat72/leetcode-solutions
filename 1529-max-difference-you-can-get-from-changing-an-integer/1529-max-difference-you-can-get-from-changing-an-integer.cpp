class Solution {
public:
    int maxDiff(int num)
{
    if (num == 0)
        return 9; 
    string a = to_string(num), b = a;
    bool ok1 = 0, ok2 = 0;
    char c1 = '0', c2 = '0', mnConvert = '0';
    if (a[0] != '9')
    {
        c1 = a[0];
        a[0] = '9';
        ok1 = 1;
    }
    if (b[0] != '1')
    {
        c2 = b[0];
        b[0] = '1';
        mnConvert = '1';
        ok2 = 1;
    }

    for (int i = 1; i < a.size(); i++)
    {
        if (!ok1 && a[i] != '9')
        {
            c1 = a[i];
            ok1 = 1;
        }
        if (!ok2 && b[i] != '0')
        {
            if (!(b[i] == '1' && b[0] == '1'))
            {
                c2 = b[i];
                ok2 = 1;
            }
        }

        if (ok1 && a[i] == c1)
            a[i] = '9';
        if (ok2 && b[i] == c2)
            b[i] = mnConvert;
    }

    return abs(stoi(a) - stoi(b));
}
};