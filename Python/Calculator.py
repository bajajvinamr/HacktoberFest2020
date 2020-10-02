import math
# This function adds two numbers 
def add(x, y):
   return x + y
# This function subtracts two numbers 
def subtract(x, y):
   return x - y
# This function multiplies two numbers
def multiply(x, y):
   return x * y
# This function divides two numbers
def divide(x, y):
   return x / y
# This function gets power of a number 
def power(x,y):
    return x**y
# This function gets square root of a number
def square_root(x):
    return math.sqrt(x)
# This function swaps 2 numbers mainly x & y
def swap(x,y):
    return y,x
# This function finds the square root with power x being the number of which square root to found is present
def sqpw(x,y):
    return x**(1/y)
print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")
print("5.Power ""NOTE :- enter the first number as a primary number and second as the power it is raised to")
print("6.Square Root NOTE :- enter the first number you want to find the square root of and second number as zero")
print("7.Swap NOTE :- first number will be swapped with another")
print("8.square root power the square root with power x being the number of which square root to found is present")
# Take input from the user 
choice = input("Enter choice(1/2/3/4/5/6/7/8):")
X = int(input("Enter first number: "))
Y = int(input("Enter second number: "))
if choice == '1':
   print(X,"+",Y,"=", add(X,Y))
elif choice == '2':
   print(X,"-",Y,"=", subtract(X,Y))
elif choice == '3':
   print(X,"*",Y,"=", multiply(X,Y))
elif choice == '4':
   print(X,"/",Y,"=", divide(X,Y))
elif choice == '5':
   print(X,"^",Y,"=", power(X,Y))
elif choice == '6':
   print("sqrt",X,"=", square_root(X))
elif choice == '7':
   print( "before swapping x=",X ,"&","y=",Y,"after swapping",swap(X,Y))
elif choice == '8':
   print(Y,"sqpw",X,"=",sqpw(X,Y))
else:
   print("Invalid input!")
