/*
 * @Author: LetMeFly
 * @Date: 2025-08-07 14:11:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-06 13:17:16
 */
pub struct Solution;
include!("1161-maximum-level-sum-of-a-binary-tree_20260106.rs");  // 这个fileName是会被脚本替换掉的

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}