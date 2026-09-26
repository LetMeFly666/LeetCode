struct FooBar {
    n: usize,
}

impl FooBar {
    fn new(n: usize) -> Self {
        FooBar { n }
    }

    fn foo<F>(&self, print_foo: F)
    where
        F: Fn(),
    {
        for _ in 0..self.n {
            // printFoo() outputs "foo". Do not change or remove this line.
            print_foo();
        }
    }

    fn bar<F>(&self, print_bar: F)
    where
        F: Fn(),
    {
        for _ in 0..self.n {
            // printBar() outputs "bar". Do not change or remove this line.
            print_bar();
        }
    }
}