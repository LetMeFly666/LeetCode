


typedef struct {
    
} Router;


Router* routerCreate(int memoryLimit) {
    
}

bool routerAddPacket(Router* obj, int source, int destination, int timestamp) {
    
}

int* routerForwardPacket(Router* obj, int* retSize) {
    
}

int routerGetCount(Router* obj, int destination, int startTime, int endTime) {
    
}

void routerFree(Router* obj) {
    
}

/**
 * Your Router struct will be instantiated and called as such:
 * Router* obj = routerCreate(memoryLimit);
 * bool param_1 = routerAddPacket(obj, source, destination, timestamp);
 
 * int* param_2 = routerForwardPacket(obj, retSize);
 
 * int param_3 = routerGetCount(obj, destination, startTime, endTime);
 
 * routerFree(obj);
*/