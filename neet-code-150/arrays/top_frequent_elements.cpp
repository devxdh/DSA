#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> record;

  for (auto num : nums) {
    record[num]++;
  }

  vector<vector<int>> buckets(nums.size() + 1);
  for (auto pair : record) {
    int num = pair.first;
    int freq = pair.second;

    buckets[freq].push_back(num);
  }

  vector<int> result;

  for (int i = buckets.size() - 1; i >= 0; i--) {
    for (int num : buckets[i]) {
      result.push_back(num);

      if (int(result.size()) == k) {
        return result;
      }
    }
  }

  return result;
}

int main() {
  vector<int> arr = {1, 1, 1, 2, 2, 2, 4, 4, 4, 4, 5};
  vector<int> result = topKFrequent(arr, 2);

  for (auto element : result) {
    cout << element << endl;
  }
  return 0;
}
