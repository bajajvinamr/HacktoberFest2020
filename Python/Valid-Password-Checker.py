#Python program to check the validity of a password enterd by the user.

symbol = ['$', '#', '@']
uppercase = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
lowercase = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
num = ['0','1','2','3','4','5','6','7','8','9']

x = True

while x:
    password = input("ENTER THE PASSWORD TO BE GENERATED !: ")

    if len(password) < 6 or len(password) > 16:
        print("The length of the pass should not be less than 6 characters or more than 16 chracters!")

    if not any(i in num for i in password):
        print("Should contain aleast 1 number between [0-9]!")
        break

    elif not any(char in uppercase for char in password):
        print("Should contain atleast 1 letter between [A-Z]!")
        break

    elif not any(char in lowercase for char in password):
        print("Should contain atleast 1 letter between [a-z]!")
        break

    elif not any(char in symbol for char in password):
        print("Should contain at least 1 character from [$#@]!")
        break

    else:
        x = False

if x:
    print("Not a Valid Password")
else:
    print("Valid Password")

