'''
INSTRUCTIONS

Press RUN
Enter first number
click enter button on the keyboard
enter operator
click enter button again
enter the second number
click SUBMIT button


FOR OPERATORS ENTER THE FOLLOWING

you can use upper or lower case for operations    
   +     for addition
   -     for subtraction
   /     for division
   *     for multiplication
   ^     for power
   r     for root
   %     for modulus
   pie   for Pie
   e     for E
   sin   for sin (trig)
   cos   for cos (trig)
   tan   for tan (trig)
   !     for factorial 
   ln    for ln (natural log)
   
error? read comment below

for PI and E you need to put any numbers just to prevent input error but write PI or E for operator.

for FACTORIAL and TRIG you need to put zero (or any number) as the first number, then the sign and last the number you want to calculate. The first number (or the zero) will not be used for calculations but it will prevent an error


THE CODE
'''
import math
print ("Are you having an error message? \nPlease read instructions in the code for help \n*************************")
firstNumber = float(input())
op = input().lower()
secondNumber = float(input())

if op == "+":
    print (firstNumber, "+", secondNumber, "=", firstNumber + secondNumber )
elif op == "-": 
    print (firstNumber, "-", secondNumber, "=", firstNumber - secondNumber )
elif op == "*":
    print (firstNumber, "*", secondNumber, "=", firstNumber * secondNumber )
elif op == "/":
    print (firstNumber, "/", secondNumber, "=", firstNumber / secondNumber )
elif op == "^":
    print (firstNumber, "^", secondNumber, "=", firstNumber ** secondNumber )
elif op == "r":
    print (firstNumber, "root", secondNumber, "=", secondNumber ** (1 / firstNumber) )
elif op == "%":
    print (firstNumber, "%", secondNumber, "=", firstNumber % secondNumber )
#factorial
elif op == "!":
    theNumber = firstNumber = secondNumber 
    secondNumber = 1
    while firstNumber > 1:
        secondNumber *= firstNumber 
        firstNumber = firstNumber - 1  
    print ("n!(", theNumber, ")=", secondNumber )
elif op == "sin":
    print ("sin(", secondNumber, ")=", math.sin(secondNumber ))
elif op == "cos":
    print ("cos(", secondNumber, ")=", math.cos
    (secondNumber ))
elif op == "tan":
    print ("tan(", secondNumber, ")=", math.tan(secondNumber ))
elif op == "pie" or op == "pi":
    print ("Pie =", math.pi)
elif op == "e":
    print = ("E =", math.e)
elif op == "ln":
    print ("ln(", secondNumber , ")= ", math.log(secondNumber))
else:
    print ("incorrect operator") 
