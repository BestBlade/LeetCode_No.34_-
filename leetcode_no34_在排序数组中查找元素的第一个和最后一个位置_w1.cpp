/*------------------------------------------------------------------|
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	两次二分查找法
*	
*	执行用时：12 ms, 在所有 C++ 提交中击败了80.96%的用户
*	内存消耗：13.6 MB, 在所有 C++ 提交中击败了93.86%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int searchLeftBound(vector<int>& nums, int target)
{
	int head = 0;
	int tail = nums.size();

	while (head < tail)
	{
		int mid = (head + tail) / 2;
		if (nums[mid] >= target)
		{
			tail = mid;
		}
		else
		{
			head = mid + 1;
		}
	}
	return head;
}

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res = { -1,-1 };

	int i = searchLeftBound(nums,target);
	int j = searchLeftBound(nums, target + 1);

	if (i == nums.size() || nums[i] != target)
	{
		return res;
	}
	else
	{
		return{ i,j - 1 };
	}

	return res;
}

int main()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 8;

	vector<int> res;
	res = searchRange(nums, target);
}