struct AnimalShelf {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AnimalShelf {

    fn new() -> Self {
        
    }
    
    fn enqueue(&self, animal: Vec<i32>) {
        
    }
    
    fn dequeue_any(&self) -> Vec<i32> {
        
    }
    
    fn dequeue_dog(&self) -> Vec<i32> {
        
    }
    
    fn dequeue_cat(&self) -> Vec<i32> {
        
    }
}

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * let obj = AnimalShelf::new();
 * obj.enqueue(animal);
 * let ret_2: Vec<i32> = obj.dequeue_any();
 * let ret_3: Vec<i32> = obj.dequeue_dog();
 * let ret_4: Vec<i32> = obj.dequeue_cat();
 */