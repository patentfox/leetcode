// https://leetcode.com/problems/read-n-characters-given-read4/

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

#include <algorithm>

int read4(char* buf4);

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char* buf, int n) {
    int orig = n;
    bool done = false;
    int write_index = 0;
    char buf4[4];
    int n_read;
    while (n >= 4) {
      n_read = read4(buf4);
      for (int i = 0; i < n_read; ++i) {
        buf[write_index++] = buf4[i];
      }
      n -= n_read;
      if (n_read < 4) {
        done = true;
        break;
      }
    }
    if (done) {
      return orig - n;
    }
    n_read = read4(buf4);
    n_read = std::min(n, n_read);
    for (int i = 0; i < n_read; ++i) {
      buf[write_index++] = buf4[i];
    }
    n -= n_read;
    return orig - n;
  }
};