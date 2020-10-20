import random
choice=random.choice(range(21))

def print_pause(msg_to_print):
    print(msg_to_print)
    time.sleep(2)

def intro(choice):
    print("the computer choose a number within the range 20" )
intro(choice)


def try1():
    
    c1=input("i guess the number is ")
    if choice == c1:
        print("your guess is correct")
    else :
        print("Incorrect, Try again..")
try1()


def hint1():
    if choice%2 == 0:
        print("Hint: The number is even")
    else:
        print("Hint:The number is odd")
hint1()

def try2():
    c2=input(" i guess the number is")
    if choice == c2:
        print("your guess is correct")
    else :
        print("Incorrect, Try again..")
try2()

def hint2():
    if 10<choice<21 :
        print("Hint: The number is greater than 10")
    elif 0<choice<11 :
        print("Hint: The number is smaller than 10")
    else :
        print("The number is notin the given range")
hint2()

def try3():
    c3=input("i guess the number is ")
    if choice == c3:
        print("your guess is correct")
    else :
        print("Incorrect, Try again..")
try3()

  
def hint3():
    if choice%3 == 0:
        print("Hint: The number is divisible by 3")
    else:
        print("Hint: The number is not divisible by 3")
hint3()

def last_try():
    c4=input("i guess the number is ")
    if choice == c4:
        print("your guess is correct")
    else :
        print("Incorrect, you were unable to guess the correct number ")
last_try()

score=int()
def t_score():
    if input == choice :
        score+=1
t_score()

    
print("the correct answer is "+ str(choice))
print("the total score is "+ str(score))



    





    
