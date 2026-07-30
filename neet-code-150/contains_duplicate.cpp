#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int> &nums) {
  set<int> seen(nums.begin(), nums.end());
  return nums.size() != seen.size();
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 4};

  bool hasDuplicate = containsDuplicate(nums);

  if (hasDuplicate) {
    cout << "The array contains a duplicate!" << endl;
  } else {
    cout << "All numbers in the array are unique." << endl;
  }

  return 0;
}
