#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN

class Solution {
private:
    // Recursive helper function
    int findMaxSum(const std::vector<int>& nums, int left, int right) {
        // Base Case: If there is only one element, return it.
        if (left == right) {
            return nums[left];
        }

        // 1. Divide: Find the middle point.
        // This prevents potential overflow for very large arrays.
        int mid = left + (right - left) / 2;

        // 2. Conquer: Recursively find the max sum in the left and right halves.
        int left_half_sum = findMaxSum(nums, left, mid);
        int right_half_sum = findMaxSum(nums, mid + 1, right);

        // 3. Combine: Find the max sum that crosses the midpoint.
        
        // Find max sum in the left part, starting from mid and going left.
        long long current_sum = 0;
        long long max_left_border_sum = INT_MIN;
        for (int i = mid; i >= left; --i) {
            current_sum += nums[i];
            if (current_sum > max_left_border_sum) {
                max_left_border_sum = current_sum;
            }
        }

        // Find max sum in the right part, starting from mid+1 and going right.
        current_sum = 0;
        long long max_right_border_sum = INT_MIN;
        for (int i = mid + 1; i <= right; ++i) {
            current_sum += nums[i];
            if (current_sum > max_right_border_sum) {
                max_right_border_sum = current_sum;
            }
        }

        // The crossing sum is the combination of the two border sums.
        long long cross_sum = max_left_border_sum + max_right_border_sum;

        // Return the maximum of the three possibilities.
        return std::max({(long long)left_half_sum, (long long)right_half_sum, cross_sum});
    }

public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        return findMaxSum(nums, 0, nums.size() - 1);
    }
};

