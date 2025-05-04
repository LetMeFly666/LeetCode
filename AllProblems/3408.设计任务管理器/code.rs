struct TaskManager {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TaskManager {

    fn new(tasks: Vec<Vec<i32>>) -> Self {
        
    }
    
    fn add(&self, user_id: i32, task_id: i32, priority: i32) {
        
    }
    
    fn edit(&self, task_id: i32, new_priority: i32) {
        
    }
    
    fn rmv(&self, task_id: i32) {
        
    }
    
    fn exec_top(&self) -> i32 {
        
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * let obj = TaskManager::new(tasks);
 * obj.add(userId, taskId, priority);
 * obj.edit(taskId, newPriority);
 * obj.rmv(taskId);
 * let ret_4: i32 = obj.exec_top();
 */