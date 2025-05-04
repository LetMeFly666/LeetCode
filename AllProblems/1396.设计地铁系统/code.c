


typedef struct {
    
} UndergroundSystem;


UndergroundSystem* undergroundSystemCreate() {
    
}

void undergroundSystemCheckIn(UndergroundSystem* obj, int id, char* stationName, int t) {
    
}

void undergroundSystemCheckOut(UndergroundSystem* obj, int id, char* stationName, int t) {
    
}

double undergroundSystemGetAverageTime(UndergroundSystem* obj, char* startStation, char* endStation) {
    
}

void undergroundSystemFree(UndergroundSystem* obj) {
    
}

/**
 * Your UndergroundSystem struct will be instantiated and called as such:
 * UndergroundSystem* obj = undergroundSystemCreate();
 * undergroundSystemCheckIn(obj, id, stationName, t);
 
 * undergroundSystemCheckOut(obj, id, stationName, t);
 
 * double param_3 = undergroundSystemGetAverageTime(obj, startStation, endStation);
 
 * undergroundSystemFree(obj);
*/