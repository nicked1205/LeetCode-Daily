import heapq
import sys

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        maxR = len(moveTime)
        maxC = len(moveTime[0])
        pq = []
        dist = [sys.maxsize] * (maxR * maxC)
        visited = set()

        heapq.heappush(pq, [0, [0, 0], 1]) 
        dist[0] = 0

        while pq:
            curDist, (curX, curY), movingTime = heapq.heappop(pq)
            if (curX, curY) in visited:
                continue
            visited.add((curX, curY))

            for dir in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
                newX, newY = curX + dir[0], curY + dir[1]

                if not (0 <= newX < maxR and 0 <= newY < maxC):
                    continue
                if curDist < moveTime[curX + dir[0]][curY + dir[1]]:
                    newDist = moveTime[curX + dir[0]][curY + dir[1]] + movingTime
                else:
                    newDist = curDist + movingTime
                if newDist < dist[newX * maxC + newY]:
                    dist[newX * maxC + newY] = newDist
                    heapq.heappush(pq, [newDist, [newX, newY], 2 if movingTime == 1 else 1])

        return dist[maxR * maxC - 1]