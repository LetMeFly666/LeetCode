interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
}


Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */