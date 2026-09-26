
var AuctionSystem = function() {
    
};

/** 
 * @param {number} userId 
 * @param {number} itemId 
 * @param {number} bidAmount
 * @return {void}
 */
AuctionSystem.prototype.addBid = function(userId, itemId, bidAmount) {
    
};

/** 
 * @param {number} userId 
 * @param {number} itemId 
 * @param {number} newAmount
 * @return {void}
 */
AuctionSystem.prototype.updateBid = function(userId, itemId, newAmount) {
    
};

/** 
 * @param {number} userId 
 * @param {number} itemId
 * @return {void}
 */
AuctionSystem.prototype.removeBid = function(userId, itemId) {
    
};

/** 
 * @param {number} itemId
 * @return {number}
 */
AuctionSystem.prototype.getHighestBidder = function(itemId) {
    
};

/** 
 * Your AuctionSystem object will be instantiated and called as such:
 * var obj = new AuctionSystem()
 * obj.addBid(userId,itemId,bidAmount)
 * obj.updateBid(userId,itemId,newAmount)
 * obj.removeBid(userId,itemId)
 * var param_4 = obj.getHighestBidder(itemId)
 */