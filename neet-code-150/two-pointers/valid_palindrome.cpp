#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;

bool isValidPalindrome(string s) {
  if (s.empty() || s.size() == 1) {
    return true;
  }

  s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !isalnum(c);
          }),
          s.end());

  transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
    return tolower(c);
  });

  int l = 0;
  int r = s.size() - 1;

  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

int main() {
  bool result = isValidPalindrome("radar");
  cout << result << endl;
  return 0;
}
