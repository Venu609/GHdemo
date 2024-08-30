#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numToIndex; // Map to store number and its index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // Find the complement
        if (numToIndex.find(complement) != numToIndex.end()) {
            // If complement is found, return the indices
            return { numToIndex[complement], i };
        }
        numToIndex[nums[i]] = i; // Store index of the current number
    }

    // If no solution is found (though problem guarantees there is exactly one solution)
    throw std::invalid_argument("No two sum solution");
}

int main() {
    // Test the function with example cases
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);
    std::cout << "Output: [" << result1[0] << "," << result1[1] << "]" << std::endl;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);
    std::cout << "Output: [" << result2[0] << "," << result2[1] << "]" << std::endl;

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = twoSum(nums3, target3);
    std::cout << "Output: [" << result3[0] << "," << result3[1] << "]" << std::endl;

    return 0;
}