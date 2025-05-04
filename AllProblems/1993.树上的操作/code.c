


typedef struct {
    
} LockingTree;


LockingTree* lockingTreeCreate(int* parent, int parentSize) {
    
}

bool lockingTreeLock(LockingTree* obj, int num, int user) {
    
}

bool lockingTreeUnlock(LockingTree* obj, int num, int user) {
    
}

bool lockingTreeUpgrade(LockingTree* obj, int num, int user) {
    
}

void lockingTreeFree(LockingTree* obj) {
    
}

/**
 * Your LockingTree struct will be instantiated and called as such:
 * LockingTree* obj = lockingTreeCreate(parent, parentSize);
 * bool param_1 = lockingTreeLock(obj, num, user);
 
 * bool param_2 = lockingTreeUnlock(obj, num, user);
 
 * bool param_3 = lockingTreeUpgrade(obj, num, user);
 
 * lockingTreeFree(obj);
*/