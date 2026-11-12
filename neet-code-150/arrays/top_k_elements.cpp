#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> seen;

        for (auto num : nums) {
            seen[num] += 1;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto pair : seen) {
            bucket[pair.second].push_back(pair.first);
        }

        vector<int> res;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (auto num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
