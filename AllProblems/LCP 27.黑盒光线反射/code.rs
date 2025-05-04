struct BlackBox {

}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BlackBox {

    fn new(n: i32, m: i32) -> Self {

    }
    
    fn open(&self, index: i32, direction: i32) -> i32 {

    }
    
    fn close(&self, index: i32) {

    }
}

/**
 * Your BlackBox object will be instantiated and called as such:
 * let obj = BlackBox::new(n, m);
 * let ret_1: i32 = obj.open(index, direction);
 * obj.close(index);
 */