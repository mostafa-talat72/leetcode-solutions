class Solution {
public:
  bool canChange(string start, string target) {

	int waitL = 0, waitR = 0;
	for (int i = 0; i < start.size(); i++) {
		char curr = start[i];
		char goal = target[i];
		if (curr == 'R')
		{
			if (waitL)
				return false;
			waitR++;
		}
		if (goal == 'L')
		{
			if (waitR)
				return false;
			waitL++;
		}

		if(goal == 'R')
		{
			if (!waitR)
				return false;
			waitR--;
		}
		if (curr == 'L')
		{
			if (!waitL)
				return false;
			waitL--;
		}
		
	}
	return waitL == 0 && waitR == 0;
}
};