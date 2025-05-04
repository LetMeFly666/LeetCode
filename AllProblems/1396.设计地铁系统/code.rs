struct UndergroundSystem {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl UndergroundSystem {

    fn new() -> Self {
        
    }
    
    fn check_in(&self, id: i32, station_name: String, t: i32) {
        
    }
    
    fn check_out(&self, id: i32, station_name: String, t: i32) {
        
    }
    
    fn get_average_time(&self, start_station: String, end_station: String) -> f64 {
        
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * let obj = UndergroundSystem::new();
 * obj.check_in(id, stationName, t);
 * obj.check_out(id, stationName, t);
 * let ret_3: f64 = obj.get_average_time(startStation, endStation);
 */