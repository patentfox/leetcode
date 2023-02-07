#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    return root == nullptr || checkNodes(root->left, root->right);
  }

 private:
  bool checkNodes(TreeNode *left_side, TreeNode *right_side) {
    if (left_side == nullptr && right_side == nullptr) {
      return true;
    }
    if (left_side == nullptr || right_side == nullptr) {
      return false;
    }
    return left_side->val == right_side->val &&
           checkNodes(left_side->left, right_side->right) &&
           checkNodes(left_side->right, right_side->left);
  }
};
