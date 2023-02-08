// https://leetcode.com/problems/roman-to-integer/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    int num = 0;
    map<char, int> charToValue = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int i = 0;
    while (i < s.size()) {
      if (i == 0 || s[i] == 'I') {
        num += charToValue[s[i]];
      } else {
        if (s[i - 1] == getSubtractor(s[i])) {
          num -= 2 * charToValue[s[i - 1]];
          num += charToValue[s[i]];
        } else {
          num += charToValue[s[i]];
        }
      }
      ++i;
    }
    return num;
  }

 private:
  char getSubtractor(char c) {
    switch (c) {
      case 'V':
      case 'X':return 'I';
      case 'L':
      case 'C':return 'X';
      case 'D':
      case 'M':return 'C';
      default:return '*';
    }
  }
};

int main() {
  Solution sol;
  assert(sol.romanToInt("III") == 3);
  assert(sol.romanToInt("IV") == 4);
  assert(sol.romanToInt("LVIII") == 58);

}

