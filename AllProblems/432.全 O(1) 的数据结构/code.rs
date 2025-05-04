struct AllOne {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AllOne {

    fn new() -> Self {
        
    }
    
    fn inc(&self, key: String) {
        
    }
    
    fn dec(&self, key: String) {
        
    }
    
    fn get_max_key(&self) -> String {
        
    }
    
    fn get_min_key(&self) -> String {
        
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * let obj = AllOne::new();
 * obj.inc(key);
 * obj.dec(key);
 * let ret_3: String = obj.get_max_key();
 * let ret_4: String = obj.get_min_key();
 */