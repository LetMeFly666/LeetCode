struct Bank {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {

    fn new(balance: Vec<i64>) -> Self {
        
    }
    
    fn transfer(&self, account1: i32, account2: i32, money: i64) -> bool {
        
    }
    
    fn deposit(&self, account: i32, money: i64) -> bool {
        
    }
    
    fn withdraw(&self, account: i32, money: i64) -> bool {
        
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * let obj = Bank::new(balance);
 * let ret_1: bool = obj.transfer(account1, account2, money);
 * let ret_2: bool = obj.deposit(account, money);
 * let ret_3: bool = obj.withdraw(account, money);
 */