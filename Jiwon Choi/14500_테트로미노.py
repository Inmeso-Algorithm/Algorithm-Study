import sys

input = sys.stdin.readline

r, c = map(int, input().split())

grid = []

for i in range(r):
    grid.append(list(map(int, input().split())))
    
def invalid_index(x, y):
    if x < 0 or y < 0 or x == r or y == c:
        return True
    else:
        return False
    
    
def square(x, y):
    if invalid_index(x, y) or invalid_index(x, y+1) or invalid_index(x+1, y) or invalid_index(x+1, y+1):
        return 0
    else:
        return grid[x][y] + grid[x][y+1] + grid[x+1][y] + grid[x+1][y+1]

def long_1(x, y):
    if invalid_index(x, y) or invalid_index(x, y+1) or invalid_index(x, y+2) or invalid_index(x, y+3):
        return 0
    else:
        return grid[x][y] + grid[x][y+1] + grid[x][y+2] + grid[x][y+3]

def long_2(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+2, y) or invalid_index(x+3, y):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+2][y] + grid[x+3][y]

def L_1(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+2, y) or invalid_index(x+2, y+1):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+2][y] + grid[x+2][y+1]
    
def L_2(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+2, y) or invalid_index(x+2, y-1):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+2][y] + grid[x+2][y-1]

def L_3(x, y):
    if invalid_index(x, y) or invalid_index(x, y+1) or invalid_index(x+1, y) or invalid_index(x+2, y):
        return 0
    else:
        return grid[x][y] + grid[x][y+1] + grid[x+1][y] + grid[x+2][y]

def L_4(x, y):
    if invalid_index(x, y) or invalid_index(x, y-1) or invalid_index(x+1, y) or invalid_index(x+2, y):
        return 0
    else:
        return grid[x][y] + grid[x][y-1] + grid[x+1][y] + grid[x+2][y]

def L_5(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x, y-1) or invalid_index(x, y-2):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x][y-1] + grid[x][y-2]

def L_6(x, y):
    if invalid_index(x, y) or invalid_index(x, y-1) or invalid_index(x, y-2) or invalid_index(x+1, y-2):
        return 0
    else:
        return grid[x][y] + grid[x][y-1] + grid[x][y-2] + grid[x+1][y-2]

def L_7(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+1, y-1) or invalid_index(x+1, y-2):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+1][y-1] + grid[x+1][y-2]

def L_8(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+1, y+1) or invalid_index(x+1, y+2):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2]
    
def sc_1(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+1, y+1) or invalid_index(x+2, y+1):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+1][y+1] + grid[x+2][y+1]

def sc_2(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+1, y-1) or invalid_index(x+2, y-1):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+1][y-1] + grid[x+2][y-1]

def sc_3(x, y):
    if invalid_index(x, y) or invalid_index(x, y-1) or invalid_index(x+1, y-1) or invalid_index(x+1, y-2):
        return 0
    else:
        return grid[x][y] + grid[x][y-1] + grid[x+1][y-1] + grid[x+1][y-2]

def sc_4(x, y):
    if invalid_index(x, y) or invalid_index(x, y-1) or invalid_index(x-1, y-1) or invalid_index(x-1, y-2):
        return 0
    else:
        return grid[x][y] + grid[x][y-1] + grid[x-1][y-1] + grid[x-1][y-2]

def T_1(x, y):
    if invalid_index(x, y) or invalid_index(x, y-1) or invalid_index(x+1, y-1) or invalid_index(x, y-2):
        return 0
    else:
        return grid[x][y] + grid[x][y-1] + grid[x+1][y-1] + grid[x][y-2]

def T_2(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+1, y-1) or invalid_index(x+2, y):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+1][y-1] + grid[x+2][y]

def T_3(x, y):
    if invalid_index(x, y) or invalid_index(x, y-1) or invalid_index(x-1, y-1) or invalid_index(x, y-2):
        return 0
    else:
        return grid[x][y] + grid[x][y-1] + grid[x-1][y-1] + grid[x][y-2]

def T_4(x, y):
    if invalid_index(x, y) or invalid_index(x+1, y) or invalid_index(x+1, y+1) or invalid_index(x+2, y):
        return 0
    else:
        return grid[x][y] + grid[x+1][y] + grid[x+1][y+1] + grid[x+2][y] 
    
ans = 0    
    
for i in range(r):
    for k in range(c):
        ans = max(ans, square(i, k), long_1(i, k), long_2(i, k), L_1(i, k), L_2(i, k), L_3(i, k), L_4(i, k), L_5(i, k), L_6(i, k), L_7(i, k), L_8(i, k), sc_1(i, k), sc_2(i, k), sc_3(i, k), sc_4(i, k), T_1(i, k), T_2(i, k), T_3(i, k), T_4(i, k))
    
    
    
print(ans)
    
    
    
    
    
    