


typedef struct {
    
} ThroneInheritance;


ThroneInheritance* throneInheritanceCreate(char* kingName) {
    
}

void throneInheritanceBirth(ThroneInheritance* obj, char* parentName, char* childName) {
    
}

void throneInheritanceDeath(ThroneInheritance* obj, char* name) {
    
}

char** throneInheritanceGetInheritanceOrder(ThroneInheritance* obj, int* retSize) {
    
}

void throneInheritanceFree(ThroneInheritance* obj) {
    
}

/**
 * Your ThroneInheritance struct will be instantiated and called as such:
 * ThroneInheritance* obj = throneInheritanceCreate(kingName);
 * throneInheritanceBirth(obj, parentName, childName);
 
 * throneInheritanceDeath(obj, name);
 
 * char** param_3 = throneInheritanceGetInheritanceOrder(obj, retSize);
 
 * throneInheritanceFree(obj);
*/