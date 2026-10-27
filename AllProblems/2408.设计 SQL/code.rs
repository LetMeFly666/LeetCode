struct SQL {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SQL {

    fn new(names: Vec<String>, columns: Vec<i32>) -> Self {
        
    }
    
    fn ins(&self, name: String, row: Vec<String>) -> bool {
        
    }
    
    fn rmv(&self, name: String, row_id: i32) {
        
    }
    
    fn sel(&self, name: String, row_id: i32, column_id: i32) -> String {
        
    }
    
    fn exp(&self, name: String) -> Vec<String> {
        
    }
}

/**
 * Your SQL object will be instantiated and called as such:
 * let obj = SQL::new(names, columns);
 * let ret_1: bool = obj.ins(name, row);
 * obj.rmv(name, rowId);
 * let ret_3: String = obj.sel(name, rowId, columnId);
 * let ret_4: Vec<String> = obj.exp(name);
 */