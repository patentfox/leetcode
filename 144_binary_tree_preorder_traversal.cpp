// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

// Definition for a binary tree node.
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> traversal;
    helper(root, traversal);
    return traversal;
  }

 private:
  void helper(TreeNode *root, vector<int> &traversal) {
    if (root != nullptr) {
      traversal.push_back(root->val);
      helper(root->left, traversal);
      helper(root->right, traversal);
    }
  }
};