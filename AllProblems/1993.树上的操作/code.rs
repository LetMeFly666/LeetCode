struct LockingTree {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LockingTree {

    fn new(parent: Vec<i32>) -> Self {
        
    }
    
    fn lock(&self, num: i32, user: i32) -> bool {
        
    }
    
    fn unlock(&self, num: i32, user: i32) -> bool {
        
    }
    
    fn upgrade(&self, num: i32, user: i32) -> bool {
        
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * let obj = LockingTree::new(parent);
 * let ret_1: bool = obj.lock(num, user);
 * let ret_2: bool = obj.unlock(num, user);
 * let ret_3: bool = obj.upgrade(num, user);
 */