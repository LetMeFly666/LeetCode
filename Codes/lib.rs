/*
 * @Author: LetMeFly
 * @Date: 2025-08-07 14:11:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-03-01 20:25:21
 */
pub struct Solution;

include!("1784-check-if-binary-string-has-at-most-one-segment-of-ones_20260307.rs");  // 这个fileName是会被脚本替换掉的

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