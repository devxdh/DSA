#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum2(vector<int> &nums, int target) {
  if (nums.empty()) {
    return {};
  }

  vector<int> result;

  int l = 0;
  int r = nums.size() - 1;

  while (l < r) {
    int sum = nums[l] + nums[r];

    if (sum == target) {
      result.push_back(l + 1);
      result.push_back(r + 1);
    }
    if (sum < target) {
      l++;
    }
    r--;
  }

  return result;
}

int main() {
  vector<int> nums = {2, 11, 7, 15};
  vector<int> result = twoSum2(nums, 9);

  cout << "result.size() = " << result.size() << endl;
  for (int i : result) {
    cout << i << endl;
  }
  return 0;
}
