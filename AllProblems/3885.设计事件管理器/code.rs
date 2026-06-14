struct EventManager {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl EventManager {

    fn new(events: Vec<Vec<i32>>) -> Self {
        
    }
    
    fn update_priority(&self, event_id: i32, new_priority: i32) {
        
    }
    
    fn poll_highest(&self) -> i32 {
        
    }
}

/**
 * Your EventManager object will be instantiated and called as such:
 * let obj = EventManager::new(events);
 * obj.update_priority(eventId, newPriority);
 * let ret_2: i32 = obj.poll_highest();
 */