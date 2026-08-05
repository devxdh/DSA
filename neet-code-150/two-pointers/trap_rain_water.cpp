#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &n) {
  if (n.empty()) {
    return 0;
  }

  int total = 0;
  int left = 0;
  int right = n.size() - 1;

  int left_max = 0;
  int right_max = 0;

  while (left < right) {
    if (n[left] < n[right]) {
      if (n[left] >= left_max) {
        left_max = n[left];
      } else {
        total += left_max - n[left];
      }
      left++;
    } else {
      if (n[right] >= right_max) {
        right_max = n[right];
      } else {
        total += right_max - n[right];
      }
      right--;
    }
  }

  return total;
}

int main() {
  vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int result = trap(nums);
  cout << result << endl;
  return 0;
}
