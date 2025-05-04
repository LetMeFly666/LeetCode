interface Array<T> {
    last(): T | -1;
}

Array.prototype.last = function() {
    
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */