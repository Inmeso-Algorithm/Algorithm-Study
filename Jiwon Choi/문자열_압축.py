def solution(s):
    retVal = len(s)
    for i in range(int(len(s) / 2)):
        cut = i + 1
        comp = ''
        numbering = 1
        calLen = len(s)
        for k in range(0, len(s), cut):
            if (comp == ''):
                comp = s[k : k+cut]
            elif (comp == s[k : k+cut]):
                    calLen -= cut
                    numbering += 1
            else:
                comp = s[k : k+cut]
                if (numbering != 1):
                    calLen += len(str(numbering))
                numbering = 1
        
        if (numbering != 1):
            calLen += len(str(numbering))
            
        if (calLen < retVal):
            retVal = calLen
    return retVal
            

j = input()
print(solution(j))



wait = input()