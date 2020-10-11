# In this Python project we Built a Game called MAX THE MONSTER
# This is a basic designed with basic python code



# Firstly we add Library to the code which we needed further
#to add library we need to do this

from random import randint

# After defining library we need to define function

def cal_monster_attack():
   return randint(monster['attack_min1'], monster['attack_max1'])

def cal_monster_heal_attack():
   return randint(monster['attack_min2'], monster['attack_max2'])

def game_ends(winner_name):
    print(f'{winner_name} won the game')


# After defing function we need to run the code till the user Exit the game

# This code will make the while loop run till the statement is false

game_running = True
game_result = []

# First loop is the number of rounds

while game_running == True:

    # After that we define the Dictionaries

    counter = 0
    new_round = True
    player = {'name': '', 'attack': 12, 'heal': 16, 'health': 100}
    monster = {'name': 'MAX THE MONSTER', 'attack_min1': 10,'attack_max1' : 80,'attack_min2': 10,'attack_max2' : 20, 'health': 100}

    print('---' * 7)
    print('Enter Player Name')
    player['name'] = input()

    print('---' * 7)


    print(player['name'] + ' has ' + str(player['health']) + ' health ')
    print(monster['name'] + ' has ' + str(monster['health']) + ' health ')

    # this wile loop run till the winner is decided

    while new_round == True:

        # In this loop we will interact with the user through user inputs

        counter = counter +1

        player_won = False
        monster_won = False

        print('---' * 7)

        print('Please select action')
        print('1) Attack')
        print('2) Heal')
        print('3) Show Results')
        print('4) Exit Game')

        player_choice = int(input())

        # Condition of the gameplay

        # Condition if the player chooses to attack

        if player_choice == 1:
            monster['health'] = monster['health'] - player['attack']
            if monster['health'] <=0:
                player_won = True

            else:
                player['health']= player['health'] - cal_monster_attack()           # Previosly We added library called randit
                if player['health'] <=0:                                            # It would add random input
                    monster_won = True

        # Condition if user chooses to heal themselfs


        elif  player_choice == 2 :
            player['health'] = player['health'] + player['heal']
            player['health'] = player['health'] - cal_monster_heal_attack()
            print('heal player')
            if player['health'] > 100:
                player['health'] = 100
            if player['health'] <= 0:
                monster_won = True


        # Condition if player Want to See the results

        elif player_choice == 3:
            for player_stats in game_result:
                print(player_stats)


        # Conditions if player chooses to Exit the Game

        elif player_choice == 4:
            game_running = False
            new_round = False


        # Statement if the user give wrong input
        else:
            print('invalid input')

        # Condition to terminate the loop

        if player_won == False and monster_won == False:
            print(player['name'] + ' has ' + str(player['health']) + ' left ')
            print(monster['name'] + ' has ' + str(monster['health']) + ' left ')

        # Condition for the winner

        elif player_won:
            game_ends(player['name'])
            round_result = {'name': player['name'], 'health': player['health'],'rounds': counter}
            game_result.append((round_result))
            new_round = False

        elif monster_won:
            game_ends(monster['name'])
            round_result = {'name': player['name'], 'health': player['health'], 'rounds': counter}
            game_result.append((round_result))
            new_round = False


# This was the game based on basic code
# Hope you get to learn some basic python functions
# If you need to add or to suggest somethin feel free
# Hope you enjoy