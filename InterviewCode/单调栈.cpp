// 单调栈解题模板 - 下一个更大元素
// 输入一个数组，返回一个等长数组，对应索引存储下一个更大元素，如果没有，则存-1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums)
{
	vector<int> ans(nums.size());
	stack<int> s;
	for (int i = nums.size() - 1; i >= 0; --i) {
		while (!s.empty() && s.top() <= nums[i]) {
			s.pop();
		}
		ans[i] = s.empty() ? -1 : s.top();
		s.push(nums[i]);
	}
	return ans;
}

// 更暖和的天气
vector<int> warmer(vector<int>& nums)
{
	vector<int> ans(nums.size());
	stack<int> s;
	for (int i = nums.size() - 1; i >= 0; i--) {
		while (!s.empty() && nums[s.top()] <= nums[i]) {
			s.pop();
		}
		ans[i] = s.empty() ? 0 : (s.top() - i);
		s.push(i);
	}
	return ans;
}



int main()
{
	vector<int> nums = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> ans = warmer(nums);
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}