import sys

input = sys.stdin.readline

class Pair:
    def __init__(self, x, y, drt):
        self.x = x
        self.y = y
        self.drt = drt

n, m = map(int, input().split())

x, y, d = map(int, input().split())

robot = Pair(x, y, d)
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def invalid_index(x, y):
    if x < 0 or y < 0 or x == n or y == m:
        return True
    else:
        return False
    
grid = []

for i in range(n):
    grid.append(list(map(int, input().split())))

while True:
    flag = False
    grid[robot.x][robot.y] = -1
    for i in range(1, 5):
        k = robot.drt - i
        if k == -1:
            k = 3
        if k == -2:
            k = 2
        if k == -3:
            k = 1
        if k == -4:
            k = 0
        
        nx = robot.x + dx[k]
        ny = robot.y + dy[k]
        
        if invalid_index(nx, ny):
            continue
        if grid[nx][ny] != 0:
            continue
        
        robot.x = nx
        robot.y = ny
        robot.drt = k
        flag = True
        break
    if flag:
        continue
    
    bx = robot.x - dx[robot.drt]
    by = robot.y - dy[robot.drt]
    
    if invalid_index(bx, by) or grid[bx][by] == 1:
        break
    else:
        robot.x = bx
        robot.y = by

ans = 0

for line in grid:
    for value in line:
        if value == -1:
            ans += 1
            
print(ans)
    
    
        

