import math

n = int(input())

pizza, result, one_half, one_quarter, three_quarter = 0.0, 0.0, 0.0, 0.0, 0.0

for i in range(n):
    numerator, denominator = map(int, input().split('/'))
    k = float(numerator / denominator)
    if k == 1 / 2:
        one_half += 1
    elif k == 1 / 4:
        one_quarter += 1
    elif k == 3 / 4:
        three_quarter += 1

k = one_quarter - three_quarter
pizza = math.ceil(one_half / 2)
if one_quarter > three_quarter:
    if one_half % 2 != 0:
        if k >= 2:
            k -= 2
            result += pizza + math.ceil(k * 1 / 4) + three_quarter
        else:
            result += pizza + three_quarter
    else:
        result = pizza + math.ceil(k * 1 / 4) + three_quarter
elif one_quarter == three_quarter:
    result = one_quarter + pizza
elif one_quarter < three_quarter:
    result = three_quarter + pizza

print(int(result))
#
