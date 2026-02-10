


typedef struct {
    
} RideSharingSystem;


RideSharingSystem* rideSharingSystemCreate() {
    
}

void rideSharingSystemAddRider(RideSharingSystem* obj, int riderId) {
    
}

void rideSharingSystemAddDriver(RideSharingSystem* obj, int driverId) {
    
}

int* rideSharingSystemMatchDriverWithRider(RideSharingSystem* obj, int* retSize) {
    
}

void rideSharingSystemCancelRider(RideSharingSystem* obj, int riderId) {
    
}

void rideSharingSystemFree(RideSharingSystem* obj) {
    
}

/**
 * Your RideSharingSystem struct will be instantiated and called as such:
 * RideSharingSystem* obj = rideSharingSystemCreate();
 * rideSharingSystemAddRider(obj, riderId);
 
 * rideSharingSystemAddDriver(obj, driverId);
 
 * int* param_3 = rideSharingSystemMatchDriverWithRider(obj, retSize);
 
 * rideSharingSystemCancelRider(obj, riderId);
 
 * rideSharingSystemFree(obj);
*/