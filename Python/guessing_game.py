from random import randint
from time import sleep

print('\033[;35mMY NAME IS THIAGO MACHINE...\033[m')
sleep(2)
pc = randint(0, 10)
print('\033[;35mI just thought of a number between 0 and 10\033[m')
sleep(2)
print('\033[;35mCan you guess?\033[m')
sleep(2)
nome = str(input('\033[;36mWhat is your name?\033[m')).strip().capitalize()
eu = ''
tentativas = 0
while pc != eu:
    eu = int(input('\033[;33mWhat is your guess?'))
    tentativas += 1
    if pc == eu:
        sleep(2)
        print('CONGRATULATIONS, {}! You got it right, I also thought of number {}'.format(nome, pc))
        print('You got it right with {} attempts'.format(tentativas))
    if pc > eu:
        sleep(2)
        print('Bigger... Try again.')
    if pc < eu:
        sleep(2)
        print('Smaller... Try again.')