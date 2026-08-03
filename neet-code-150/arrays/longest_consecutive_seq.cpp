#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestConsecutiveSequence(vector<int> &nums) {
  if (nums.empty()) {
    return 0;
  }

  sort(nums.begin(), nums.end());

  int longestStreak = 0;
  int currentStreak = 0;

  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      continue;
    }

    if (nums[i] == nums[i - 1] + 1) {
      currentStreak++;
    }

    else {
      longestStreak = max(longestStreak, currentStreak);
      currentStreak = 1;
    }
  }

  return max(longestStreak, currentStreak);
}

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  int result = longestConsecutiveSequence(nums);
  cout << result << endl;
  return 0;
}
