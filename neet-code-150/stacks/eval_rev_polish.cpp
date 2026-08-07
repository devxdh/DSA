
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int evalRPN(const vector<string> &tokens) {
  stack<int> s;

  for (auto token : tokens) {
    if (
        token == "/" ||
        token == "*" ||
        token == "+" ||
        token == "-") {

      char op = token[0];

      int a = s.top();
      s.pop();

      int b = s.top();
      s.pop();

      if (op == '+')
        s.push(b + a);
      else if (op == '-')
        s.push(b - a);
      else if (op == '*')
        s.push(b * a);
      else if (op == '/')
        s.push(b / a);

    } else {
      int num = stoi(token);
      s.push(num);
    }
  }
  return s.top();
}

int main() {
  vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  int result = evalRPN(tokens);
  cout << "Result: " << result << endl;
  return 0;
}
