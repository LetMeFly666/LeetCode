struct Router {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Router {

    fn new(memoryLimit: i32) -> Self {
        
    }
    
    fn add_packet(&self, source: i32, destination: i32, timestamp: i32) -> bool {
        
    }
    
    fn forward_packet(&self) -> Vec<i32> {
        
    }
    
    fn get_count(&self, destination: i32, start_time: i32, end_time: i32) -> i32 {
        
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * let obj = Router::new(memoryLimit);
 * let ret_1: bool = obj.add_packet(source, destination, timestamp);
 * let ret_2: Vec<i32> = obj.forward_packet();
 * let ret_3: i32 = obj.get_count(destination, startTime, endTime);
 */