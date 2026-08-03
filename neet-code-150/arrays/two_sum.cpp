#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> seen;

  for (int i = 0; i < int(nums.size()); i++) {
    int diff = target - nums[i];
    if (seen.count(diff) > 0) {
      return {seen[diff], i};
    }

    seen[nums[i]] = i;
  }

  return {};
}

int main() {
  vector<int> nums = {3, 2, 4};

  vector<int> result = twoSum(nums, 6);

  if (result.size() == 0) {
    cout << "Result is empty" << endl;
  }

  for (int i = 0; i < int(result.size()); i++) {
    cout << result[i] << endl;
  }

  return 0;
}
