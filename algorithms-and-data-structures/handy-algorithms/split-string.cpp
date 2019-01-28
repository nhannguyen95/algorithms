#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<string> splitAll(const string & s, const string & delim) {
  vector<string> tokens;
  size_t last = 0;
  for(size_t next = 0; (next = s.find(delim, last)) != s.npos; ) {
    if (last < next)
      tokens.push_back(s.substr(last, next - last));
    last = next + delim.size();
  }
  if (last < s.size()) tokens.push_back(s.substr(last));
  return tokens;
}

int main() {
  string s = "  ab cd efg gh   ";
  vector<string> tokens = splitAll(s, " ");
  for(string token :tokens)
  	cout << "'" << token << "'" << '\n';
  return 0;
}
