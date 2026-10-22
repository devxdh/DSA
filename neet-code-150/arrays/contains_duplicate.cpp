#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        return seen.size() == nums.size() ? false : true;
    }
};
