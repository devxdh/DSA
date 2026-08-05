#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &nums) {
  int maxA = 0;
  int currentA = 0;

  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    int minNum = min(nums[left], nums[right]);
    currentA = minNum * (right - left);

    if (nums[left] < nums[right]) {
      left++;
    } else {
      right--;
    }
    maxA = max(maxA, currentA);
  }

  return maxA;
}

int main() {
  vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  int result = maxArea(nums);
  cout << result << endl;
  return 0;
}
