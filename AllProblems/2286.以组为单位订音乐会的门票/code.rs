struct BookMyShow {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BookMyShow {

    fn new(n: i32, m: i32) -> Self {
        
    }
    
    fn gather(&self, k: i32, max_row: i32) -> Vec<i32> {
        
    }
    
    fn scatter(&self, k: i32, max_row: i32) -> bool {
        
    }
}

/**
 * Your BookMyShow object will be instantiated and called as such:
 * let obj = BookMyShow::new(n, m);
 * let ret_1: Vec<i32> = obj.gather(k, maxRow);
 * let ret_2: bool = obj.scatter(k, maxRow);
 */