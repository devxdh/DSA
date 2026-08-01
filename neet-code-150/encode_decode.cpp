#include <string>
#include <vector>
using namespace std;

string encode(vector<string> &strs) {
  string encoded;
  for (const string &s : strs) {
    encoded += to_string(s.size()) + "#!" + s;
  }

  return encoded;
}

vector<string> decode(string s) {
  vector<string> decoded;

  size_t i = 0;

  while (i < s.size()) {
    size_t delimiter_index = s.find("#!", i);
    string length_str = s.substr(i, delimiter_index - i);
    int len = stoi(length_str);

    i = delimiter_index + 2;

    string origin_str = s.substr(i, len);
    decoded.push_back(origin_str);

    i += len;
  }

  return decoded;
}
