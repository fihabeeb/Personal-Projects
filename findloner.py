def solution(A):
    inputArr = A
    buffArr = []
    pairs = []
    buffArr.append(1919191)
    pairs.append(1919191)
    for a in inputArr:
        foundinbuff = False
        for x in buffArr:
            if x == a:
                pairs.append(a)
                buffArr.remove(a)
                print("added to pairs")
                foundinbuff = True
        if foundinbuff == False:
            foundinpairs = False
            for y in pairs:
                if y == a:
                    continue
            if foundinpairs == False:
                buffArr.append(a)
                print("added to buffer")
    value = 0
    found = True
    print("Input arr: " + str(inputArr))
    print("Buffer: " + str(buffArr))
    print("Pairs: " + str(pairs))
    for a in inputArr:
        for b in pairs:
            if a == b:
                found = False
                break
        if found == False:
            found = True
            continue
        else:
            value = a
    return value

def solutionB(A):
    if len (A) > 0:
        mydic = {}
        index = 0
        found = False
        nopairs = []
        for x in A:
            found = False
            mydic[index] = x
            index += 1
            for l in range (0,index - 1):
                if mydic[l] == x:
                    print(mydic)
                    found = True
                    break
                if found == True:
                    break
            if found == False:
                nopairs.append(x)
            if found and len(nopairs) > 0:
                for l in nopairs:
                    if l == x:
                        nopairs.remove(l)
                        break
        return nopairs[0]
    else:
        return


def solutionC(A):
    loners = []
    found = False
    for x in A:
        found = False
        for y in loners:
            if x == y:
                found = True
                loners.remove(y)
                break
        if found == False:
            loners.append(x)
    return loners[0]

def solutionD(A):
    mydict = {}
    for x in A:
        if x in mydict:
            mydict[x] += 1
        else:
            mydict[x] = 1
    return min(mydict, key = mydict.get)
print(solutionD([9,8,9,7,8,7,4,4,1,3,1,96,96,55,55,3,44,44,12,13,13,15,19,10,13,15,19,10]))
