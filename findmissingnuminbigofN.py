#I dont understand this one (I dont get what they are inputting, its so vague how can i understand my mistake)
def solution(A):
    possibleList = []
    A.sort()
    for x in range (0,(len(A))):
        if x <= (len(A) - 2):
            if (A[x] + 1 == A[x+1]):
                continue
            else:
                possibleList.append(A[x] + 1)
    if len(possibleList) > 0:
        return possibleList[0]
    else:
        return 0

arr = [1,3,2,6,4]

print(solution(arr))