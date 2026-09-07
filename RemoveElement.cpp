#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val);
};

int Solution::removeElement(vector<int>& nums, int val) {
    int len = 0;
    vector<int> result;
    for(size_t i = 0; i < nums.size(); i++)
    {
        if(nums[i] == val)
            continue;
        result.push_back(nums[i]);
    }

    len = static_cast<int>(result.size());
    nums = result;
    return (len);
}


int main() {
    Solution sol;

    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    std::vector<int> expectedNums1 = {2, 2};

    int k1 = sol.removeElement(nums1, val1);

    assert(k1 == expectedNums1.size());

    std::sort(nums1.begin(), nums1.begin() + k1);

    for (int i = 0; i < k1; ++i) {
        assert(nums1[i] == expectedNums1[i]);
    }

    std::cout << "Test Case 1 Passed! k = " << k1 << "\n";
    exit(1);

    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    std::vector<int> expectedNums2 = {0, 0, 1, 3, 4};

    int k2 = sol.removeElement(nums2, val2);

    assert(k2 == expectedNums2.size());

    std::sort(nums2.begin(), nums2.begin() + k2);

    for (int i = 0; i < k2; ++i) {
        assert(nums2[i] == expectedNums2[i]);
    }

    std::cout << "Test Case 2 Passed! k = " << k2 << "\n";

    return 0;
}