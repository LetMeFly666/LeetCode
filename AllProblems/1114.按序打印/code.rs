struct Foo {
    
};

impl Foo {
    fn new() -> Self {
        Foo {
            
        }
    }

    fn first<F>(&self, print_first: F)
    where
        F: FnOnce(),
    {
        // Do not change this line
        print_first();
    }

    fn second<F>(&self, print_second: F)
    where
        F: FnOnce(),
    {
        // Do not change this line
        print_second();
    }

    fn third<F>(&self, print_third: F)
    where
        F: FnOnce(),
    {
        // Do not change this line
        print_third();
    }
}