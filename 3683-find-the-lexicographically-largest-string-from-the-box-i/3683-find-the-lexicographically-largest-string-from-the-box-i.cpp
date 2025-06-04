class Solution {
public:
   string answerString(string word, int numFriends)
{
    if (numFriends == 1)
        return word;
    string result = "";
    char mx = *max_element(word.begin(),word.end());
    int siz = word.size() - numFriends + 1;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == mx )
        {
            result = max(result, word.substr(i, siz));
        }
    }
    return result;
    
}
};