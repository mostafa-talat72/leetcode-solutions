class ProductOfNumbers {
public:
	vector<int>prefix_prod;
	int last0;
	ProductOfNumbers() {
		prefix_prod.push_back(1);
		last0 = -1;
	}

	void add(int num) {
		prefix_prod.push_back(num);
		if (num == 0)
			last0 = prefix_prod.size() - 1;
		else if(prefix_prod[prefix_prod.size() - 2] !=0)
			prefix_prod.back() *= prefix_prod[prefix_prod.size() - 2];
	}

	int getProduct(int k) {
		int ans = 0, tst = prefix_prod.size() - k - 1;
		
		if (tst < last0)
			ans= 0;
		else {
			if (last0 == tst)
				ans = prefix_prod.back();
			else
				ans = prefix_prod.back() / prefix_prod[tst];
		}
		return ans;
	}
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */