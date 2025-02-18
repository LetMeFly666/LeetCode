/*
 * @Author: LetMeFly
 * @Date: 2025-02-18 10:17:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-18 10:48:00
 * @Description: HALF -- 先不写了
 */
import java.util.Map;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

class RangeFreqQuery {
    private Map<Integer, List<Integer>> ma = new HashMap<>();

    public RangeFreqQuery(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            ma.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
    }
    
    public int query(int left, int right, int value) {
        if (!ma.containsKey(value)) {
            return 0;
        }
        List<Integer> v = ma.get(value);
        // System.out.println(Collections.binarySearch(v, right + 1));
        // System.out.println(Collections.binarySearch(v, left));
        return Collections.binarySearch(v, left) - Collections.binarySearch(v, right + 1);  // WA
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */