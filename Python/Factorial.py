
def fact(n):
   if n==0:
      return 1
   return n*fact(n-1)



# To take input from the user
n = int(input("Enter a number: "))

factorial = 1

# checking wheather the number is negative, positive or zero
if n < 0:
   print("factorial does not exist for negative numbers")
elif n == 0:
   print("The factorial of 0 is 1")
else:
#    for i in range(1,num + 1):
#        factorial = factorial*i
#    print("The factorial of",n,"is",factorial)

     print("factorial of the number is :"+fact(n))
