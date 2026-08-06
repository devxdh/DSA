#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
  stack<char> result;
  unordered_map<char, char> bracketMap = {
      {')', '('},
      {']', '['},
      {'}', '{'},
  };

  for (char c : s) {
    if (bracketMap.count(c)) {

      char top_element = !result.empty() ? result.top() : '#';
      if (bracketMap[c] == top_element) {
        result.pop();
      } else {
        return false;
      }
    } else {
      result.push(c);
    }
  }

  return result.empty();
}

int main() {
  string s = "([])";
  bool result = isValid(s);
  cout << result << endl;
  return 0;
}
