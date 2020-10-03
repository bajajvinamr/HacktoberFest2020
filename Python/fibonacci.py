# Fibonacci Sequence
import math

def fibonacci(number):
    if (number <= 1):
        return number
    else:
        return (fibonacci(number-1) + fibonacci(number-2)) 

n = int(input("Input a number: "))

print(fibonacci(n))
