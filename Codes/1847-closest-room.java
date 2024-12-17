/*
 * @Author: LetMeFly
 * @Date: 2024-12-16 12:40:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-16 22:21:59
 */
import java.util.TreeSet;
import java.util.Arrays;

class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        Integer[] queryIdx = new Integer[queries.length];  // int的话不支持sort的Comparator
        Arrays.setAll(queryIdx, i -> i);
        Arrays.sort(queryIdx, (i, j) -> queries[j][1] - queries[i][1]);
        Arrays.sort(rooms, (a, b) -> b[1] - a[1]);
        TreeSet<Integer> canIds = new TreeSet<>();
        int[] ans = new int[queries.length];
        int locR = 0;
        for (int locQI = 0; locQI < queryIdx.length; locQI++) {
            int queryId = queries[queryIdx[locQI]][0], querySize = queries[queryIdx[locQI]][1];
            while (locR < rooms.length && rooms[locR][1] >= querySize) {
                canIds.add(rooms[locR++][0]);
            }
            if (canIds.isEmpty()) {
                ans[queryIdx[locQI]] = -1;
                continue;
            }
            Integer floor = canIds.floor(queryId);
            Integer ceil = canIds.ceiling(queryId);
            if (floor == null) {
                ans[queryIdx[locQI]] = ceil;
            } else if (ceil == null) {
                ans[queryIdx[locQI]] = floor;
            } else {
                if (Math.abs(floor - queryId) <= Math.abs(ceil - queryId)) {
                    ans[queryIdx[locQI]] = floor;
                } else {
                    ans[queryIdx[locQI]] = ceil;
                }
            }
        }
        return ans;
    }
}