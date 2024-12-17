'''
Author: LetMeFly
Date: 2024-12-16 11:01:23
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-16 12:39:10
'''
if False:  # FirstTry - HALF - set无法bisect_left
    from typing import List
    from bisect import bisect_left

    class Solution:
        def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
            queryIdx = [i for i in range(1, len(queries) + 1)]
            queryIdx.sort(lambda x: -queries[x][1])
            rooms.sort(lambda x: -x[1])
            canIds = set()
            locR = 0
            ans = [-1] * len(queries)
            for locQI in range(len(queryIdx)):
                queryId, querySize = queries[queryIdx[locQI]]
                while locR < len(rooms) and rooms[locR][1] >= querySize:
                    canIds.add(rooms[locR][0])
                    locR += 1
                if not canIds:
                    continue
                it = bisect_left(canIds, queryId)
                idDiff = abs


from typing import List
from sortedcontainers import SortedList
from bisect import bisect_left

class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        queryIdx = [i for i in range(len(queries))]
        queryIdx.sort(key=lambda x: -queries[x][1])
        rooms.sort(key=lambda x: -x[1])
        canIds = SortedList()
        ans = [-1] * len(queries)
        locR = 0
        for locQI in range(len(queries)):
            queryId, querySize = queries[queryIdx[locQI]]
            while locR < len(rooms) and rooms[locR][1] >= querySize:
                canIds.add(rooms[locR][0])
                locR += 1
            if not canIds:
                continue
            it = bisect_left(canIds, queryId)
            # print(f'bisect_left({canIds, queryId}) = {it}')  # bisect_left((SortedList([1, 2, 3]), 5)) = 3
            if it == len(canIds) or (it and abs(canIds[it - 1] - queryId) <= abs(canIds[it] - queryId)):
                it -= 1
            ans[queryIdx[locQI]] = canIds[it]
        return ans