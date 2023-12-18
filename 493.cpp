// Explanation: The reverse pairs are:
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
// nums = [1,3,2,3,1]
// [1, 3, 2]
// [3, 1]
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);
        for (int i = low, j = mid + 1; i <= mid; ++i)
        {
            while (j <= high && nums[i] > 2LL * nums[j])
                ++j;
            count += j - (mid + 1);
        }
        sort(nums.begin() + low, nums.begin() + high + 1);
        return count;
    }
};