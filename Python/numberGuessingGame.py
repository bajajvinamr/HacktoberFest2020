import random

print("lets play a game")
print("I have a secret number. Lets see if you can guess it.")
print()


Input = 0
def ask():
    try:
        global Input
        Input = int(input("Guess a number >>> "))
    except:
        ask()


number_of_times = []


sec_number = random.randint(0,100)
ask()

won = False
while len(number_of_times) < 11:
    if Input < sec_number:
        print("The number is Smaller than the input")
        number_of_times.append(Input)
        ask()
        
    elif Input > sec_number:
        print("The number is Bigger than the input")
        number_of_times.append(Input)
        ask()

    elif Input == sec_number:
        print("You won. The number is ", Input)
        won = True
        break

if not won:
    print("Sorry, you lost. Better luck next time.")
