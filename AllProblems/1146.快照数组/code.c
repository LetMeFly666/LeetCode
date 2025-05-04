


typedef struct {
    
} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {
    
}

void snapshotArraySet(SnapshotArray* obj, int index, int val) {
    
}

int snapshotArraySnap(SnapshotArray* obj) {
    
}

int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {
    
}

void snapshotArrayFree(SnapshotArray* obj) {
    
}

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);
 
 * int param_2 = snapshotArraySnap(obj);
 
 * int param_3 = snapshotArrayGet(obj, index, snap_id);
 
 * snapshotArrayFree(obj);
*/