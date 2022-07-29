from sys import stdin

input = stdin.readline

n, r, c = map(int, input().split())
n = 2**n

def sol(n, r, c, offset):
    if n == 2:
        if r == 0:
            if c == 0:
                return offset + 0
            elif c == 1:
                return offset + 1
        if r == 1:
            if c == 0:
                return offset + 2
            elif c == 1:
                return offset + 3
    else:
        half = n // 2
        if r < half:
            if c < half:
                return sol(half, r % half, c % half, offset + (half**2) * 0)
            elif c >= half:
                return sol(half, r % half, c % half, offset + (half**2) * 1)
        elif r >= half:
            if c < half:
                return sol(half, r % half, c % half, offset + (half**2) * 2)
            elif c >= half:
                return sol(half, r % half, c % half, offset + (half**2) * 3)

print(sol(n, r, c, 0))
        
    