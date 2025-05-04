struct SnapshotArray {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SnapshotArray {

    fn new(length: i32) -> Self {
        
    }
    
    fn set(&self, index: i32, val: i32) {
        
    }
    
    fn snap(&self) -> i32 {
        
    }
    
    fn get(&self, index: i32, snap_id: i32) -> i32 {
        
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * let obj = SnapshotArray::new(length);
 * obj.set(index, val);
 * let ret_2: i32 = obj.snap();
 * let ret_3: i32 = obj.get(index, snap_id);
 */