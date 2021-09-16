
/*

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//
//	2Sum 问题 
//	输入一个数组nums和一个目标和target，请返回nums中能够凑出target的两个元素的值
//

// Case1 数组nums无序，返回一组满足要求的数据
vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); i++) {
		int other = target - nums[i];
		if (map.count(other) && map[other] != i) {
			return { nums[i], other };
		}
	}
	return {};
}

// Case2 数组nums有序 返回一组满足要求的数据
vector<int> twoSum(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int sum = nums[left] + nums[right];
		if (sum == target) {
			return { nums[left], nums[right] };
		}
		else if (sum < target) {
			right++;
		}
		else if (sum > target) {
			left--;
		}
	}
	return {};
}

// Case3 数组nums无序，数组中可能有重复数字，返回所有满足要求的数据
vector<vector<int>> twoSum2(vector<int>& nums, int target)
{
	vector<vector<int>> res;
	// 先对数组进行排序，时间复杂度O(NlogN)
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		int leftVal = nums[left];
		int rightVal = nums[right];
		int sum = leftVal + rightVal;
		if (sum < target) {
			while (left < right && nums[left] == leftVal) left++;
		}
		else if (sum > target) {
			while (left < right && nums[right] == rightVal) right--;
		}
		else {
			res.push_back({ leftVal, rightVal });
			while (left < right && nums[left] == leftVal) left++;
			while (left < right && nums[right] == rightVal) right--;
		}
	}
	return res;
}

// Case4 求三数之和的问题

vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
	vector<vector<int>> res;
	int left = start, right = nums.size() - 1;
	while (left < right) {
		int lv = nums[left], rv = nums[right];
		int sum = lv + rv;
		if (sum < target) {
			while (left < right && nums[left] == lv) left++;
		}
		else if (sum > target) {
			while (left < right && nums[right] == rv) right--;
		}
		else {
			res.push_back({ lv, rv });
			while (left < right && nums[left] == lv) left++;
			while (left < right && nums[right] == rv) right--;
		}
	}
	return res;
}

vector<vector<int>> threeSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for (int i = 0; i < nums.size() - 2; i++) {
		vector<vector<int>> curRes = twoSum(nums, i + 1, target - nums[i]);
		for (auto vec : curRes) {
			vec.push_back(nums[i]);
			res.push_back(vec);
		}
		while (i < nums.size() - 3 && nums[i] == nums[i + 1]) i++;
	}
	return res;
}

vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for (int i = start; i < nums.size() - 2; i++) {
		vector<vector<int>> curRes = twoSum(nums, i + 1, target - nums[i]);
		for (auto vec : curRes) {
			vec.push_back(nums[i]);
			res.push_back(vec);
		}
		while (i < nums.size() - 3 && nums[i] == nums[i + 1]) i++;
	}
	return res;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	if (nums.empty() || nums.size() < 3) return {};
	return threeSum(nums, 0);
}

// Case5 4Sum问题

vector<vector<int>> fourSum(vector<int>& nums){
	if (nums.size() < 4) return {};
	return fourSum(nums, 0);
}

vector<vector<int>> fourSum(vector<int>& nums, int target){
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for (int i = 0; i < nums.size() - 3; i++) {
		vector<vector<int>> curRes = threeSum(nums, i + 1, target - nums[i]);
		for (auto vec : curRes) {
			vec.push_back(nums[i]);
			res.push_back(vec);
		}
		while (i < nums.size() - 4 && nums[i] == nums[i + 1]) i++;
	}
	return res;
}


// Case6 针对NSum问题  在2Sum的基础上，递归解决

class Solution {
public:

	vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target) {
		vector<vector<int>> res;
		if (nums.size() < n || n < 2) return {};
		if (n == 2) {
			int left = start, right = nums.size() - 1;
			while (left < right) {
				int leftVal = nums[left], rightVal = nums[right];
				int sum = leftVal + rightVal;
				if (sum < target) {
					while (left < right && nums[left] == leftVal) left++;
				}
				else if (sum > target) {
					while (left < right && nums[right] == rightVal) right--;
				}
				else {
					res.push_back({ leftVal, rightVal });
					while (left < right && nums[left] == leftVal) left++;
					while (left < right && nums[right] == rightVal) right--;
				}
			}
		}
		else {
			for (int i = start; i < nums.size() - n + 1; i++) {
				vector<vector<int>> curRes = nSum(nums, n - 1, i + 1, target - nums[i]);
				for (auto vec : curRes) {
					vec.push_back(nums[i]);
					res.push_back(vec);
				}
				while (i < nums.size() - n && nums[i] == nums[i + 1]) i++;
			}
		}
		return res;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nSum(nums, 3, 0, 0);
	}
};


*/