struct AuctionSystem {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AuctionSystem {

    fn new() -> Self {
        
    }
    
    fn add_bid(&self, user_id: i32, item_id: i32, bid_amount: i32) {
        
    }
    
    fn update_bid(&self, user_id: i32, item_id: i32, new_amount: i32) {
        
    }
    
    fn remove_bid(&self, user_id: i32, item_id: i32) {
        
    }
    
    fn get_highest_bidder(&self, item_id: i32) -> i32 {
        
    }
}

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * let obj = AuctionSystem::new();
 * obj.add_bid(userId, itemId, bidAmount);
 * obj.update_bid(userId, itemId, newAmount);
 * obj.remove_bid(userId, itemId);
 * let ret_4: i32 = obj.get_highest_bidder(itemId);
 */