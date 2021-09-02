// ����ջ����ģ�� - ��һ������Ԫ��
// ����һ�����飬����һ���ȳ����飬��Ӧ�����洢��һ������Ԫ�أ����û�У����-1

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

// ��ů�͵�����
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