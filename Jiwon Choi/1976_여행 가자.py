from sys import stdin
input = stdin.readline

n = int(input())
m = int(input())

INF = int(10e9)

adj_mat = [ [] ]
    
for i in range(1, n+1):
    adj_mat.append([0] + list(map(int, input().split())))

for i in range(1, n+1):
    adj_mat[i][i] = 1
    
nodes = list(map(int, input().split()))

for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            adj_mat[j][k] = 1 if adj_mat[i][j] and adj_mat[i][k] else adj_mat[j][k]

flag = True

for i in range(len(nodes)-1):
    if not adj_mat[nodes[i]][nodes[i+1]]:
        flag = False
        break

if flag:
    print("YES")
else:
    print("NO")
        
wait=input()