struct ThroneInheritance {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ThroneInheritance {

    fn new(kingName: String) -> Self {
        
    }
    
    fn birth(&self, parent_name: String, child_name: String) {
        
    }
    
    fn death(&self, name: String) {
        
    }
    
    fn get_inheritance_order(&self) -> Vec<String> {
        
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * let obj = ThroneInheritance::new(kingName);
 * obj.birth(parentName, childName);
 * obj.death(name);
 * let ret_3: Vec<String> = obj.get_inheritance_order();
 */