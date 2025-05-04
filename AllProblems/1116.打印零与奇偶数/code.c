typedef struct {
    int n;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    
}

void even(ZeroEvenOdd* obj) {
    
}

void odd(ZeroEvenOdd* obj) {
    
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    
}