


typedef struct {
    
} AuctionSystem;


AuctionSystem* auctionSystemCreate() {
    
}

void auctionSystemAddBid(AuctionSystem* obj, int userId, int itemId, int bidAmount) {
    
}

void auctionSystemUpdateBid(AuctionSystem* obj, int userId, int itemId, int newAmount) {
    
}

void auctionSystemRemoveBid(AuctionSystem* obj, int userId, int itemId) {
    
}

int auctionSystemGetHighestBidder(AuctionSystem* obj, int itemId) {
    
}

void auctionSystemFree(AuctionSystem* obj) {
    
}

/**
 * Your AuctionSystem struct will be instantiated and called as such:
 * AuctionSystem* obj = auctionSystemCreate();
 * auctionSystemAddBid(obj, userId, itemId, bidAmount);
 
 * auctionSystemUpdateBid(obj, userId, itemId, newAmount);
 
 * auctionSystemRemoveBid(obj, userId, itemId);
 
 * int param_4 = auctionSystemGetHighestBidder(obj, itemId);
 
 * auctionSystemFree(obj);
*/