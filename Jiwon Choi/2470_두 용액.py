import sys

input = sys.stdin.readline

plus = []
minus = []
big = 0
small = 0
result = 2100000000

n = int(input())
nums = list(map(int, input().split()))
nums.sort()

front = 0
back = n-1

while(True):
    if front == back:
        break
    
    tempsum = nums[front] + nums[back]
    
    if abs(tempsum) < abs(result):
        big = nums[back]
        small = nums[front]
        result = tempsum
    
    
    if tempsum > 0 :
        back -= 1
        continue
    
    elif tempsum < 0:
        front += 1
        continue
    else:
        break

print(small, end=' ')
print(big)