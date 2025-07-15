class Solution {
public:
    bool isValid(string word) { 
	 
	 
	 bool hasDigit = false, hasConsonant = false, hasVowel = false;
     for (char c : word)
     {
         if (isdigit(c))
         {
             continue;
         }
		 if (!isalpha(c))
		 {
			 return false;
         }
         c = tolower(c);
         if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
             hasVowel = true;
         else
             hasConsonant = true;
     }
     return hasConsonant && hasVowel && word.length() >= 3;
 }
};