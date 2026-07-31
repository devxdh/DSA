#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> groups;

  for (string str : strs) {
    string key = str;
    sort(key.begin(), key.end());
    groups[key].push_back(str);
  }

  vector<vector<string>> result;

  for (auto pair : groups) {
    result.push_back(pair.second);
  }

  return result;
}

int main() {
  vector<string> group = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = groupAnagrams(group);

  for (const auto &row : result) {
    for (const auto &element : row) {
      cout << element << endl;
    }

    cout << endl;
  }

  return 0;
}
