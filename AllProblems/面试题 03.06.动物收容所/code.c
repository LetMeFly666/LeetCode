


typedef struct {
    
} AnimalShelf;


AnimalShelf* animalShelfCreate() {
    
}

void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize) {
    
}

int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize) {
    
}

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize) {
    
}

int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize) {
    
}

void animalShelfFree(AnimalShelf* obj) {
    
}

/**
 * Your AnimalShelf struct will be instantiated and called as such:
 * AnimalShelf* obj = animalShelfCreate();
 * animalShelfEnqueue(obj, animal, animalSize);
 
 * int* param_2 = animalShelfDequeueAny(obj, retSize);
 
 * int* param_3 = animalShelfDequeueDog(obj, retSize);
 
 * int* param_4 = animalShelfDequeueCat(obj, retSize);
 
 * animalShelfFree(obj);
*/