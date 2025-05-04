struct Cashier {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Cashier {

    fn new(n: i32, discount: i32, products: Vec<i32>, prices: Vec<i32>) -> Self {
        
    }
    
    fn get_bill(&self, product: Vec<i32>, amount: Vec<i32>) -> f64 {
        
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * let obj = Cashier::new(n, discount, products, prices);
 * let ret_1: f64 = obj.get_bill(product, amount);
 */