struct Allocator {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Allocator {

    fn new(n: i32) -> Self {
        
    }
    
    fn allocate(&self, size: i32, m_id: i32) -> i32 {
        
    }
    
    fn free_memory(&self, m_id: i32) -> i32 {
        
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * let obj = Allocator::new(n);
 * let ret_1: i32 = obj.allocate(size, mID);
 * let ret_2: i32 = obj.free_memory(mID);
 */