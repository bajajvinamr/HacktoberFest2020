import random

low,high=int(input('Enter lower limit : ')),int(input('Enter higher limit : '))
secret = low + int(random.random()*(high-low+1))
chances=5
win = False
while chances:
    guess = int(input('Guess the secret number : '))
    chances-=1
    if(guess==secret):
        print('\nCongratulations......you win the game!!!! :)')
        win = True
        break
    elif secret<guess:
        print('\nSecret no. is less than guessed no.!')
    else:
        print('\nSecret no. is greater tha guessed no.!')

if not win:
    print('\nYou lost the game!!! :(')