firstLine = input().split(' ') ###firstLine안의 value 순서대로 n, m, x, y, K

map1 = []
loc = [0, 0]
dice = ['0', '0', '0', '0', '0', '0'] ### idx1이 위, idx3이 바닥, idx4가 서쪽, idx5가 동쪽 

def rollDice(dice, drt):
    retVal = ['0', '0', '0', '0', '0', '0']
    if(drt == '2'):
        retVal[0] = dice[0]
        retVal[1] = dice[4]
        retVal[2] = dice[2]
        retVal[3] = dice[5]
        retVal[4] = dice[3]
        retVal[5] = dice[1]
        return retVal
    elif(drt == '1'):
        retVal[0] = dice[0]
        retVal[1] = dice[5]
        retVal[2] = dice[2]
        retVal[3] = dice[4]
        retVal[4] = dice[1]
        retVal[5] = dice[3]
        return retVal
    elif(drt == '3'):
        retVal[0] = dice[3]
        retVal[1] = dice[0]
        retVal[2] = dice[1]
        retVal[3] = dice[2]
        retVal[4] = dice[4]
        retVal[5] = dice[5]
        return retVal
    elif(drt == '4'):
        retVal[0] = dice[1]
        retVal[1] = dice[2]
        retVal[2] = dice[3]
        retVal[3] = dice[0]
        retVal[4] = dice[4]
        retVal[5] = dice[5]
        return retVal
    else:
        return -1

for i in range(int(firstLine[0])): ### map11 정보 입력받기
    row = input().split(' ')
    map1.append(row)

task = input().replace(' ','') ### 이동명령 입력받기 1234 순서대로 동서남북

loc[0] = int(firstLine[2]) ### 주사위의 x 좌표 
loc[1] = int(firstLine[3]) ### 주사위의 y 좌표


for t in task:
    if t == '1': ### 동쪽으로 이동
        if loc[1] == int(firstLine[1]) - 1:
            continue
        else:
            loc[1] += 1 ### 주사위 좌표이동
            dice = rollDice(dice, t) ### 주사위 굴리기
            dx = loc[0]
            dy = loc[1]
            if map1[dx][dy] == '0':
                map1[dx][dy] = str(dice[1])
            else:
                dice[1] = map1[dx][dy]
                map1[dx][dy] = '0'
            print(dice[3])                            
    elif t == '2': ### 서쪽으로 이동
        if loc[1] == 0:
            continue
        else:
            loc[1] -= 1 ### 주사위 좌표이동
            dice = rollDice(dice, t) ### 주사위 굴리기
            dx = loc[0]
            dy = loc[1]
            if map1[dx][dy] == '0':
                map1[dx][dy] = str(dice[1])
            else:
                dice[1] = map1[dx][dy]
                map1[dx][dy] = '0'
            print(dice[3])  
    elif t == '3': ### 북쪽으로 이동
        if loc[0] == 0:
            continue
        else:
            loc[0] -= 1 ### 주사위 좌표이동
            dice = rollDice(dice, t) ### 주사위 굴리기
            dx = loc[0]
            dy = loc[1]

            if map1[dx][dy] == '0':
                map1[dx][dy] = str(dice[1])
            else:
                dice[1] = map1[dx][dy]
                map1[dx][dy] = '0'
            print(dice[3])  
    elif t == '4': ### 남쪽으로 이동
        if loc[0] == int(firstLine[0]) - 1:
            continue
        else:
            loc[0] += 1 ### 주사위 좌표이동
            dice = rollDice(dice, t) ### 주사위 굴리기
            dx = loc[0]
            dy = loc[1]

            if map1[dx][dy] == '0':
                map1[dx][dy] = str(dice[1])
            else:
                dice[1] = map1[dx][dy]
                map1[dx][dy] = '0'
            print(dice[3])  
    else:
        pass
    '''
    print("Task " + t + " is done..." )
    print(dice)
    print(loc)
    for v in map1:
        print(v)
    print()
    print()
    '''

wait = input()