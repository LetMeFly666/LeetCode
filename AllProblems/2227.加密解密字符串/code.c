


typedef struct {
    
} Encrypter;


Encrypter* encrypterCreate(char* keys, int keysSize, char** values, int valuesSize, char** dictionary, int dictionarySize) {
    
}

char* encrypterEncrypt(Encrypter* obj, char* word1) {
    
}

int encrypterDecrypt(Encrypter* obj, char* word2) {
    
}

void encrypterFree(Encrypter* obj) {
    
}

/**
 * Your Encrypter struct will be instantiated and called as such:
 * Encrypter* obj = encrypterCreate(keys, keysSize, values, valuesSize, dictionary, dictionarySize);
 * char* param_1 = encrypterEncrypt(obj, word1);
 
 * int param_2 = encrypterDecrypt(obj, word2);
 
 * encrypterFree(obj);
*/