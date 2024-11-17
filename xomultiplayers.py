xo_array = [1,2,3,4,5,6,7,8,9]

game_Over = False

def win_Condition():
    if xo_array[0] == xo_array[1] == xo_array[2]:
        return True
    elif xo_array[3] == xo_array[4] == xo_array[5]:
        return True
    elif xo_array[6] == xo_array[7] == xo_array[8]:
        return True
    elif xo_array[0] == xo_array[3] == xo_array[6]:
        return True
    elif xo_array[1] == xo_array[4] == xo_array[7]:
        return True
    elif xo_array[2] == xo_array[5] == xo_array[8]:
        return True
    elif xo_array[0] == xo_array[4] == xo_array[8]:
        return True
    elif xo_array[2] == xo_array[4] == xo_array[6]:
        return True
    else:
        return False



print(xo_array[0], "|",xo_array[1], "|", xo_array[2])
print("---------")
print(xo_array[3], "|",xo_array[4], "|", xo_array[5])
print("---------")
print(xo_array[6], "|",xo_array[7], "|", xo_array[8])

player_1 = False
player_Input = 0
while game_Over == False:
    if player_1 == False:
        player_Input = input("Player 1 choose slot: ")
        xo_array[int(player_Input) - 1] = 'X'
        player_1 = True

    else:
        player_Input = input("Player 2 choose slot: ")
        xo_array[int(player_Input) - 1] = 'O'
        player_1 = False

    print(xo_array[0], "|",xo_array[1], "|", xo_array[2])
    print("---------")
    print(xo_array[3], "|",xo_array[4], "|", xo_array[5])
    print("---------")
    print(xo_array[6], "|",xo_array[7], "|", xo_array[8])

    if win_Condition() == True:
        game_Over = True
        if player_1 == True:
            print("X is the winner ")
        else:
            print("O is the winner")
