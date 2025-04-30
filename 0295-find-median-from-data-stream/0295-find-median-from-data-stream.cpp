class MedianFinder {
public:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int siz = 0;
	MedianFinder() {
		left = priority_queue<int>();
		right = priority_queue<int, vector<int>, greater<int>>();
	}

	void addNum(int num) {
		if(!left.empty() && left.top() >= num)
			left.push(num);
		else
			right.push(num);
		
		siz++;
		if(siz&1){
			if(left.size()<right.size())
			{
				left.push(right.top());
				right.pop();
			}
		}else{
			if(left.size()>right.size())
			{
				right.push(left.top());
				left.pop();
			}else if(right.size()>left.size())
			{
				left.push(right.top());
				right.pop();
			}
		}
		
	}

	double findMedian() {
		if(siz&1)
		{
			return left.top();
		}
		return (left.top() + right.top()) / 2.0;
	}
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */