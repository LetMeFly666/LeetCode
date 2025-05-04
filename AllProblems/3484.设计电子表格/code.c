


typedef struct {
    
} Spreadsheet;


Spreadsheet* spreadsheetCreate(int rows) {
    
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {
    
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {
    
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {
    
}

void spreadsheetFree(Spreadsheet* obj) {
    
}

/**
 * Your Spreadsheet struct will be instantiated and called as such:
 * Spreadsheet* obj = spreadsheetCreate(rows);
 * spreadsheetSetCell(obj, cell, value);
 
 * spreadsheetResetCell(obj, cell);
 
 * int param_3 = spreadsheetGetValue(obj, formula);
 
 * spreadsheetFree(obj);
*/