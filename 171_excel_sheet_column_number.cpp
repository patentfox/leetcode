// https://leetcode.com/problems/excel-sheet-column-title/

#include <cassert>
#include <string>
using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle) { 
      result *= 26;
      result += toInt(c);
    }
    return result;
  }

 private:
  int toInt(char c) { return c - 'A' + 1; }
};

int main() {
  Solution obj;
  assert(obj.titleToNumber("A") == 1);
  assert(obj.titleToNumber("Z") == 26);
  assert(obj.titleToNumber("AA") == 27);
  assert(obj.titleToNumber("AZ") == 52);
}
