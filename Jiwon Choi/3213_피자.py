import math

half = 0
quarter = 0
threeFourths = 0
pizza = 0

n=int(input())

for i in range(n):
    inp = input()
    if(inp[2] == '2'):
        half += 1
    elif(inp[0] == '1'):
        quarter += 1
    else:
        threeFourths += 1
        
pizza = math.ceil(half/2) + quarter + threeFourths

while(quarter != 0 and threeFourths != 0):
    quarter -= 1
    threeFourths -= 1
    pizza -= 1

if(half % 2 == 1 and quarter > 0):
    if (quarter == 1):
        pizza -= 1
        quarter -= 1
    else:
        pizza -= 2
        quarter -= 2

pizza -= quarter - math.ceil(quarter / 4)
        
print(pizza)


    
        
input("")