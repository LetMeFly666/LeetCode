


typedef struct {
    
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char* homepage) {
    
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    
}

void browserHistoryFree(BrowserHistory* obj) {
    
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/