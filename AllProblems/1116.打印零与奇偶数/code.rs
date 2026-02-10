struct ZeroEvenOdd {
    n: i32
}

impl ZeroEvenOdd {
    fn new(n: i32) -> Self {

        ZeroEvenOdd {
            n
        }
    }

    // printNumber(x) prints the integer x
    fn zero<F>(&self, print_number: F)
    where
        F: Fn(i32),
    {
        
    }

    fn even<F>(&self, print_number: F)
    where
        F: Fn(i32),
    {
        
    }

    fn odd<F>(&self, print_number: F)
    where
        F: Fn(i32),
    {
        
    }
}