### Tic-Tac-Toe-The game

#declarations
d = {'i1':' ','i2':' ','i3':' ','i4':' ','i5':' ','i6':' ','i7':' ','i8':' ','i9':' '}
game_flag = 1
chance_flag = True
chance_count= 0
check_flag = 1
max_turns = 9

def end():
    global check_flag,chance_flag
    if(check_flag == 0):
        if(chance_flag == False):
            print('Player1 won the game!')
            while(1):
                replay = input('Wanna play again!Enter Y for yes, N for no!')
                if(replay.lower() == 'y'):
                    check_flag = 1
                    chance_flag = True
                    for i in range(1,10):
                        d['i' + str(i)] = ' '
                    game_start(1)
                    break
                elif(replay.lower() == 'n'):
                    game_start(0)
                    break
                else:
                    print('Please enter the correct character!')
        else:
            print('Player2 won the game!')
            while(1):
                replay = input('Wanna play again!Enter Y for yes, N for no!')
                if(replay.lower() == 'y'):
                    check_flag = 1
                    chance_flag = True
                    for i in range(1,10):
                        d['i' + str(i)] = ' '
                    game_start(1)
                    break
                elif(replay.lower() == 'n'):
                    game_start(0)
                    break
                else:
                    print('Please enter the correct character!')
    else:
        print("\nGame Over! It's a DRAW!\n")
        while(1):
            replay = input('Wanna play again!Enter Y for yes, N for no!')
            if(replay.lower() == 'y'):
                check_flag = 1
                chance_flag = True
                for i in range(1,10):
                    d['i' + str(i)] = ' '
                game_start(1)
                break
            elif(replay.lower() == 'n'):
                game_start(0)
                break
            else:
                print('Please enter the correct character!')

def check():
    global check_flag
    winning_list = [('1','4','7'),('2','5','8'),('3','6','9'),('1','2','3'),('4','5','6'),('7','8','9'),('1','5','9'),('3','5','7')]
    for tup in winning_list:
        if((d['i'+tup[0]] == d['i' + tup[1]]) and (d['i'+tup[0]] == d['i' + tup[2]]) and (d['i'+tup[1]] == d['i' + tup[2]]) and d['i'+tup[0]]!=' ' and d['i'+tup[1]]!=0 and d['i'+tup[2]]!=0):
            check_flag = 0
        else:
            pass

def chance(f):
    global chance_flag
    check()
    if(f == True and ' ' in d.values() and check_flag == 1):
        print("It's your turn player1!\n")
        turn_player1()
        chance_flag = False
        chance(chance_flag)
    elif(f == False and ' ' in d.values() and check_flag == 1):
        print("It's your turn player2!\n")
        turn_player2()
        chance_flag = True
        chance(chance_flag)
    else:
        end()






def print_grid(key,flag):
    if(flag == True):
        d['i' + key] = 'X'
    else:
        d['i' + key] = 'O'

    print(' {} | {} | {} '.format(d['i1'],d['i2'],d['i3']))
    print('-----------')
    print(' {} | {} | {} '.format(d['i4'],d['i5'],d['i6']))
    print('-----------')
    print(' {} | {} | {} '.format(d['i7'],d['i8'],d['i9']))
    print('\n')


def turn_player1():
    print('Enter the number corresponding to the position in grid where you intend to place X\n')
    while(1):
        number1 = input()
        if(number1.isnumeric()):
            if(int(number1) not in range(1,10)):
                print('Please enter a valid position number!')
            elif(d['i' + number1] != ' '):
                print('The position is occupied, please enter some other position number!')
            elif(d['i' + number1] == ' ' and int(number1) in range (1,10)):
                print_grid(number1,chance_flag)
                break
        else:
            print('Invalid entry! Please enter correct number!')


def turn_player2():
    print('Enter the number corresponding to the position in grid where you intend to place O\n')
    while(1):
        number2 = input()
        if(number2.isnumeric()):
            if(int(number2) not in range(1,10)):
                print('Please enter a valid position number!')
            elif(d['i' + number2] != ' '):
                print('The position is occupied, please enter some other position number!')
            elif(d['i' + number2] == ' ' and int(number2) in range (1,10)):
                print_grid(number2,chance_flag)
                break
        else:
            print('Invalid entry! Please enter correct number!')


def instructions():
    print('\n')
    print('\n')
    print('******************************** Welcome to the TIC TAC TOE game! ********************************')
    print('\n')
    print('This is a 2-player game where player1 will be X, and the player2 will be O')
    print('\n')
    print('Each player will get a chance to insert their letter into the grid alternatively,starting from player1')
    print('\n')
    print('The one who fills either a row,a column or a diagonal with his/her letter first wins!')
    print('\n')
    print('If any of the players is unable to do so, the game would be considered a draw!')
    print('\n')
    print('Enjoy!')
    print('\n')
    print('#####################################################################################################')
    print('\n')
    print('\n')


def game_start(num):
    if(num == 1):
        instructions()

        #Input the names of players
        player1 = input('Enter your name player1: ')
        player2 = input('Enter your name player2: ')

        print('\n')

        print('Each player will have to enter the number corresponding to the \nposition on the grid where they intend to place their letter!\n ')
        print(' 1 | 2 | 3 ')
        print('-----------')
        print(' 4 | 5 | 6 ')
        print('-----------')
        print(' 7 | 8 | 9 ')

        print("\nLet's start!\n\n")
        chance(chance_flag)
    else:
        print('\nGame has ended!')






game_start(game_flag)


    
