#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> seen;
        for (int i = 0; i < s.size(); i++) {
            seen[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (seen[t[i]] == 0) {
                return false;
            }

            seen[t[i]]--;
        }

        return true;
    }
};
