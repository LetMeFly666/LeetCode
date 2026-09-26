struct DiningPhilosophers;

impl DiningPhilosophers {
    fn new() -> Self {
        DiningPhilosophers
    }

    // Callbacks are like LeetCode: each used exactly once
    fn wants_to_eat<F1, F2, F3, F4, F5>(
        &self,
        philosopher: i32,
        pick_left_fork: F1,
        pick_right_fork: F2,
        eat: F3,
        put_left_fork: F4,
        put_right_fork: F5,
    )
    where
        F1: FnOnce(),
        F2: FnOnce(),
        F3: FnOnce(),
        F4: FnOnce(),
        F5: FnOnce(),
    {
        // TODO: implement your dining philosophers solution here
        // You can translate your C++ logic into Rust inside this function.
    }
}