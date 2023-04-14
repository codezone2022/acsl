#include <bits/stdc++.h>
using namespace std;

void recursion(vector<long>& nums, int idx, long sumsL, long sumsR, long& res) {
	if(idx >= nums.size()) {
		res = min(res, abs(sumsL-sumsR)); // Done dividing and compare sums
		return;
	}
	long num = nums[idx]; // Take a number from the nums array
	recursion(nums, idx+1, sumsL + num, sumsR, res); // Add this number to the left group and move on
	recursion(nums, idx+1, sumsL, sumsR + num, res); // Add this number to the right group and move on
	return;
}

int main() {
	long n;
	cin >> n;
	vector<long> nums(n,0);
	for(long i = 0; i < n; ++i)
		cin >> nums[i];
	long res = INT_MAX;
	recursion(nums, 0, 0, 0, res);
	cout << res << endl;
	return 0;
}
