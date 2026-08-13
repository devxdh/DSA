#include <iostream>
#include <vector>

int search(std::vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (nums[m] > target) {
            r = m - 1;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            return m;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    std::cout << search(nums, 9) << std::endl;
    return 0;
}
