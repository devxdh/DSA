#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isValidAnagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<char, int> seen;
  for (int i = 0; i < int(s.size()); i++) {
    seen[s[i]]++;
  }

  for (int i = 0; i < int(t.size()); i++) {
    if (seen.count(t[i]) == 0) {
      return false;
    }

    seen[t[i]]--;

    if (seen[t[i]] < 0) {
      return false;
    }
  }

  return true;
}

int main() {
  bool result = isValidAnagram("anaaram", "anagram");
  cout << "result: " << result << endl;
  return 0;
}
