class Solution {
public:
    
string robotWithString(string s)
{


    map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }
    string ans = "";
    stack<char> st;
    for (auto c : s)
    {
        if (c == mp.begin()->first)
        {
            ans += c;
            mp[c]--;
            if (mp[c] == 0)
            {
                mp.erase(c);
            }
            while (!st.empty() && !mp.empty() && st.top() <= mp.begin()->first)
            {
                ans += st.top();
                st.pop();
            }
        }
        else
        {
            st.push(c);
            mp[c]--;
            if (mp[c] == 0)
            {
                mp.erase(c);
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
};