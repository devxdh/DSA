#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> &t) {
  vector<int> answer(t.size(), 0);
  stack<int> s;

  for (size_t i = 0; i < t.size(); ++i) {
    while (!s.empty() && t[i] > t[s.top()]) {
      int prev = s.top();
      s.pop();
      answer[prev] = i - prev;
    }

    s.push(i);
  }
  return answer;
}

int main() {
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> result = dailyTemperatures(temperatures);

  for (auto e : result) {
    cout << e << ", ";
  }
  cout << endl;

  return 0;
}
