import sys
input = sys.stdin.readline

arr = []
count = 0
endpoint = 0

n = int(input())

for i in range(n):
    pair = input().split()
    arr.append(list(map(int, pair)))
    
arr.sort(key=lambda x: (x[1], x[0]))

for pair in arr:
    if pair[0] >= endpoint:
        count += 1
        endpoint = pair[1]

print(count)
