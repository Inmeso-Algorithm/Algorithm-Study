from sys import stdin
from copy import deepcopy
input = stdin.readline

class Fireball:
    def __init__(self, mass, speed, drt):
        self.mass = mass
        self.speed = speed
        self.drt = drt
        
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

n, m, k = map(int, input().split()) ### n은 grid의 크기, m은 파이어볼의 개수, k는 마법사 상어의 이동명령 횟수

grid = [[[] for _ in range(n)] for _ in range(n)]

for _ in range(m): ### 파이어볼들의 정보를 입력받음
    r, c, mass, speed, drt = map(int, input().split())
    grid[r-1][c-1].append(Fireball(mass, speed, drt))
    
def magic_order(): ### 마법사 상어의 이동명령을 구현한 함수
    next_grid = [[[] for _ in range(n)] for _ in range(n)]
    
    for i in range(n): ###파이어볼의 이동
        for j in range(n):
            for k in range(len(grid[i][j])):
                nx = (i + grid[i][j][k].speed*dx[grid[i][j][k].drt] + n) % n
                ny = (j + grid[i][j][k].speed*dy[grid[i][j][k].drt] + n) % n
                
                next_grid[nx][ny].append(grid[i][j][k])
    
    for i in range(n): ### 이동 후 같은 공간에 있는 파이어볼 합체
        for j in range(n):
            if len(next_grid[i][j]) <= 1: ### 한 공간에 파이어볼이 1개 이하라면 합치지 않음
                continue
            
            merged_mass = 0
            merged_speed = 0
            amount = len(next_grid[i][j])
            drt_check = next_grid[i][j][0].drt % 2
            drt_flag = True
            
            for k in range(amount):
                merged_mass += next_grid[i][j][k].mass
                merged_speed += next_grid[i][j][k].speed
                if drt_check != next_grid[i][j][k].drt % 2:
                    drt_flag = False
            
            next_grid[i][j].clear() ### 기존에 있던 파이어볼들을 삭제함
            
            for p in range(4):
                mass = int(merged_mass/5)
                if mass == 0:
                    break
                speed = int(merged_speed/amount)
                if drt_flag:
                    drt = p*2
                else:
                    drt = p*2 + 1
                next_grid[i][j].append(Fireball(mass, speed, drt))
                
    return next_grid
                
for _ in range(k):
    grid = deepcopy(magic_order())
        
ans = 0
for line in grid:
    for fireballs in line:
        for fireball in fireballs:
            ans += fireball.mass

print(ans)
    
