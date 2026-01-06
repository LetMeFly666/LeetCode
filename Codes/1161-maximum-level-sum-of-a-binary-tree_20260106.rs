/*
 * @Author: LetMeFly
 * @Date: 2026-01-06 10:19:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-06 13:26:09
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
use std::collections::VecDeque;

impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 1;
        let mut maximum = -1000000000;
        let mut layer_num = 0;
        let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        if let Some(r) = root {
            q.push_back(r);
        }
        while !q.is_empty() {
            layer_num += 1;
            let mut layer_sum = 0;
            let size: usize = q.len();
            for _ in 0..size {
                let node_rc: Rc<RefCell<TreeNode>> = q.pop_front().unwrap();
                let node: std::cell::Ref<'_, TreeNode> = node_rc.borrow();
                layer_sum += node.val;
                if let Some(left) = node.left.clone() {
                    q.push_back(left);
                }
                if let Some(right) = node.right.clone() {
                    q.push_back(right);
                }
            }
            if layer_sum > maximum {
                maximum = layer_sum;
                ans = layer_num;
            }
        }
        ans
    }
}