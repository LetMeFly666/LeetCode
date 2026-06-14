


typedef struct {
    
} EventManager;


EventManager* eventManagerCreate(int** events, int eventsSize, int* eventsColSize) {
    
}

void eventManagerUpdatePriority(EventManager* obj, int eventId, int newPriority) {
    
}

int eventManagerPollHighest(EventManager* obj) {
    
}

void eventManagerFree(EventManager* obj) {
    
}

/**
 * Your EventManager struct will be instantiated and called as such:
 * EventManager* obj = eventManagerCreate(events, eventsSize, eventsColSize);
 * eventManagerUpdatePriority(obj, eventId, newPriority);
 
 * int param_2 = eventManagerPollHighest(obj);
 
 * eventManagerFree(obj);
*/