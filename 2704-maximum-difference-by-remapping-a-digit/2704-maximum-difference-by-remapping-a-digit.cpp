class Solution {
public:
    int minMaxDifference(int num) { 
	
	
	string mx = to_string(num), mn;
    mn = mx;
    char mxDigit = mn[0], convertDigit;
    bool ok = 0;
    for (int i = 0; i < mn.size(); i++)
    {
        if (mn[i] == mxDigit)
            mn[i] = '0';
        if (ok == 0 && mx[i] == '9')
            continue;
        else if (ok == 0 && mx[i] != '9')
        {
            convertDigit = mx[i];
            ok = 1;
		}
        if (mx[i] == convertDigit)
            mx[i] = '9';
	}

	return stoi(mx) - stoi(mn);
}
};