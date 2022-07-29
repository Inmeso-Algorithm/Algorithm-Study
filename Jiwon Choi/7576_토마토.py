from collections import deque
import sys

input = sys.stdin.readline

num = input().split(' ')
num = list(map(int, num))

intmax = 100000000
day = 0
grid = []
dist = []
tomato_loc = []
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]


def invalid_index(x, y):
    if x < 0 or y < 0 or x == num[1] or y == num[0]:
        return True
    else:
        return False
    

def bfs(locations):
    day = 0
    queue = deque()
    for loc in locations:
        dist[loc[0]][loc[1]] = loc[2]
        queue.append(loc)
        
    while(len(queue) != 0):
        x, y, distance = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if invalid_index(nx, ny):
                continue
            if grid[nx][ny] == -1 or dist[nx][ny] <= dist[x][y] + 1:
                continue
            
            dist[nx][ny] = distance + 1
            if dist[nx][ny] > day:
                day = dist[nx][ny]
            queue.append([nx, ny, distance + 1])
            
    for i in range(num[1]):
        for k in range(num[0]):
            if dist[i][k] == intmax and grid[i][k] == 0:
                return -1
    return day
        
        
        
for i in range(num[1]):
    line = input().split(' ')
    grid.append(list(map(int, line)))
    temp = []
    for k in range(num[0]):
        temp.append(intmax)
        if grid[i][k] == 1:
            tomato_loc.append([i, k, 0])
    dist.append(temp)

print(bfs(tomato_loc))
