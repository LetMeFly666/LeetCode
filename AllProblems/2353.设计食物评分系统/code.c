


typedef struct {
    
} FoodRatings;


FoodRatings* foodRatingsCreate(char** foods, int foodsSize, char** cuisines, int cuisinesSize, int* ratings, int ratingsSize) {
    
}

void foodRatingsChangeRating(FoodRatings* obj, char* food, int newRating) {
    
}

char* foodRatingsHighestRated(FoodRatings* obj, char* cuisine) {
    
}

void foodRatingsFree(FoodRatings* obj) {
    
}

/**
 * Your FoodRatings struct will be instantiated and called as such:
 * FoodRatings* obj = foodRatingsCreate(foods, foodsSize, cuisines, cuisinesSize, ratings, ratingsSize);
 * foodRatingsChangeRating(obj, food, newRating);
 
 * char* param_2 = foodRatingsHighestRated(obj, cuisine);
 
 * foodRatingsFree(obj);
*/