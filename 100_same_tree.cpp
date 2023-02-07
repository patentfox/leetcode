//
//  same_tree.cpp
//  Leetcode
//
//  Created by Kaustubh Bansal on 08.02.22.
//

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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr) {
      return q == nullptr;
    }
    if (q == nullptr) {
      return false;
    }
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
