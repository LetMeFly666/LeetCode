


typedef struct {
    
} MovieRentingSystem;


MovieRentingSystem* movieRentingSystemCreate(int n, int** entries, int entriesSize, int* entriesColSize) {
    
}

int* movieRentingSystemSearch(MovieRentingSystem* obj, int movie, int* retSize) {
    
}

void movieRentingSystemRent(MovieRentingSystem* obj, int shop, int movie) {
    
}

void movieRentingSystemDrop(MovieRentingSystem* obj, int shop, int movie) {
    
}

int** movieRentingSystemReport(MovieRentingSystem* obj, int* retSize, int** retColSize) {
    
}

void movieRentingSystemFree(MovieRentingSystem* obj) {
    
}

/**
 * Your MovieRentingSystem struct will be instantiated and called as such:
 * MovieRentingSystem* obj = movieRentingSystemCreate(n, entries, entriesSize, entriesColSize);
 * int* param_1 = movieRentingSystemSearch(obj, movie, retSize);
 
 * movieRentingSystemRent(obj, shop, movie);
 
 * movieRentingSystemDrop(obj, shop, movie);
 
 * int** param_4 = movieRentingSystemReport(obj, retSize, retColSize);
 
 * movieRentingSystemFree(obj);
*/