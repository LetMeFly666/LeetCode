/*
 * @Author: LetMeFly
 * @Date: 2026-02-08 13:40:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-08 14:03:07
 */
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

struct BalanceTree {
    ok: bool
}

impl BalanceTree {
    pub fn dfs(&mut self, root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if root.is_none() || !self.ok {
            return 0;
        }
        let root = root.unwrap();
        let left = self.dfs(root.borrow().left.clone());
        let right = self.dfs(root.borrow().right.clone());
        if (left - right).abs() > 1 {
            self.ok = false;
        }
        left.max(right) + 1
    }
}

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut balance_tree = BalanceTree{ok: true};
        balance_tree.dfs(root);
        balance_tree.ok
    }
}
