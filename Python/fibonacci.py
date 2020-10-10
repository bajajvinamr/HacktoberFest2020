# Fibonacci Sequence
import math

def fibonacci(number):
    if (number <= 1):
        return number
    else:
        return (fibonacci(number-1) + fibonacci(number-2)) 

n = int(input("Input a number: "))

print(fibonacci(n))
# Python program to display the Fibonacci sequence

def recur_fibo(n):
   if n <= 1:
       return n
   else:
       return(recur_fibo(n-1) + recur_fibo(n-2))

nterms = 10

# check if the number of terms is valid
if nterms <= 0:
   print("Plese enter a positive integer")
else:
   print("Fibonacci sequence:")
   for i in range(nterms):
       print(recur_fibo(i))
