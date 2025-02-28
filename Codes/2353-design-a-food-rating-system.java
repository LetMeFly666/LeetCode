/*
 * @Author: LetMeFly
 * @Date: 2025-02-28 12:31:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-28 12:58:08
 * @Say: Java是真复杂
 */
import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;


final class Pair<K extends Comparable<K>, V extends Comparable<V>> implements Comparable<Pair<K, V>> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K first() {
        return key;
    }

    public V second() {
        return value;
    }

    @Override
    public int compareTo(Pair<K, V> other) {
        int keyCompare = this.key.compareTo(other.key);
        if (keyCompare != 0) {
            return keyCompare;
        }
        return this.value.compareTo(other.value);
    }

    @Override
    public String toString() {
        return "Pair{" + "key=" + key + ", value=" + value + '}';
    }
}


class FoodRatings {
    private Map<String, Pair<String, Integer>> f2cr = new HashMap<>();
    private Map<String, TreeSet<Pair<Integer, String>>> c2rf = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++) {
            f2cr.put(foods[i], new Pair<>(cuisines[i], ratings[i]));
            c2rf.computeIfAbsent(cuisines[i], k -> new TreeSet<>());
            c2rf.get(cuisines[i]).add(new Pair<>(-ratings[i], foods[i]));
        }
    }
    
    public void changeRating(String food, int newRating) {
        Pair<String, Integer> temp = f2cr.get(food);
        String cuisine = temp.first();
        int rating = temp.second();
        f2cr.put(food, new Pair<>(cuisine, newRating));

        TreeSet<Pair<Integer, String>> list = c2rf.get(cuisine);
        list.remove(new Pair<>(-rating, food));
        list.add(new Pair<>(-newRating, food));
    }
    
    public String highestRated(String cuisine) {
        return c2rf.get(cuisine).first().second();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */